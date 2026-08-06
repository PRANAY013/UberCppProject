#pragma once
#include <array>
#include <cstddef>
#include <type_traits>

namespace infrastructure {

template<typename T, std::size_t Capacity>
class ObjectPool {
    struct FreeNode { FreeNode* next; };
    static_assert(sizeof(T) >= sizeof(FreeNode), "T too small for pool");

    std::aligned_storage_t<sizeof(T), alignof(T)> storage_[Capacity];
    FreeNode* free_head_{nullptr};
public:
    ObjectPool() noexcept {
        for (std::size_t i = 0; i < Capacity - 1; ++i)
            reinterpret_cast<FreeNode*>(&storage_[i])->next =
                reinterpret_cast<FreeNode*>(&storage_[i+1]);
        reinterpret_cast<FreeNode*>(&storage_[Capacity-1])->next = nullptr;
        free_head_ = reinterpret_cast<FreeNode*>(&storage_[0]);
    }
    T* allocate() noexcept {
        if (!free_head_) return nullptr;
        FreeNode* node = free_head_;
        free_head_ = node->next;
        return reinterpret_cast<T*>(node);
    }
    void deallocate(T* ptr) noexcept {
        auto* node = reinterpret_cast<FreeNode*>(ptr);
        node->next = free_head_;
        free_head_ = node;
    }
};

} // namespace infrastructure
