#include "PaymentsGateway.h"
#include <iostream>

namespace infrastructure {
namespace payments {

PaymentsGateway::PaymentsGateway() {}

bool PaymentsGateway::processPayment(const std::string& userId, double amount, const std::string& paymentMethod) {
    std::cout << "  [PaymentsGateway] Processing payment for user " << userId
              << ", amount $" << amount << " via " << paymentMethod << "..." << std::endl;
    // Mock implementation: always succeed for now
    return true;
}

bool PaymentsGateway::refund(const std::string& transactionId, double amount) {
    std::cout << "  [PaymentsGateway] Refunding transaction " << transactionId
              << ", amount $" << amount << "..." << std::endl;
    // Mock implementation: always succeed for now
    return true;
}

} // namespace payments
} // namespace infrastructure
