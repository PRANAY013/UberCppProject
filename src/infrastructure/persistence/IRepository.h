#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <optional>
#include <vector>

namespace infrastructure {
namespace persistence {

// Generic interface for a repository.
// T is the type of the entity (e.g., Rider, Driver, Trip).
// ID is the type of the entity's ID.
template <typename T, typename ID>
class IRepository {
public:
    virtual ~IRepository() = default;

    virtual void save(const T& entity) = 0;
    virtual std::optional<T> findById(const ID& id) const = 0;
    virtual std::vector<T> findAll() const = 0;
    virtual void remove(const ID& id) = 0;
};

} // namespace persistence
} // namespace infrastructure

#endif // IREPOSITORY_H
