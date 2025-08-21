#ifndef INMEMORYRIDERREPOSITORY_H
#define INMEMORYRIDERREPOSITORY_H

#include "IRepository.h"
#include "../../domain/rider/Rider.h"
#include <unordered_map>

namespace infrastructure {
namespace persistence {

class InMemoryRiderRepository : public IRepository<domain::Rider, int> {
public:
    InMemoryRiderRepository();

    void save(const domain::Rider& rider) override;
    std::optional<domain::Rider> findById(const int& id) const override;
    std::vector<domain::Rider> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, domain::Rider> riders;
};

} // namespace persistence
} // namespace infrastructure

#endif // INMEMORYRIDERREPOSITORY_H
