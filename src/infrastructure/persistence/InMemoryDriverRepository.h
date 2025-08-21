#ifndef INMEMORYDRIVERREPOSITORY_H
#define INMEMORYDRIVERREPOSITORY_H

#include "IRepository.h"
#include "../../domain/driver/Driver.h"
#include <unordered_map>

namespace infrastructure {
namespace persistence {

class InMemoryDriverRepository : public IRepository<domain::Driver, int> {
public:
    InMemoryDriverRepository();

    void save(const domain::Driver& driver) override;
    std::optional<domain::Driver> findById(const int& id) const override;
    std::vector<domain::Driver> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, domain::Driver> drivers;
};

} // namespace persistence
} // namespace infrastructure

#endif // INMEMORYDRIVERREPOSITORY_H
