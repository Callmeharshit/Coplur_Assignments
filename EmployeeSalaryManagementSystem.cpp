#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Logger to log activities
class Logger {
public:
    static void Log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

// Abstraction for Employee
class IEmployee {
public:
    virtual ~IEmployee() = default;
    virtual double CalculateSalary() const = 0;
    virtual std::string GetDetails() const = 0;
};

// Concrete Employee: Permanent Employee
class PermanentEmployee : public IEmployee {
private:
    double basicPay;
    double bonus;

public:
    PermanentEmployee(double basicPay, double bonus)
        : basicPay(basicPay), bonus(bonus) {}

    double CalculateSalary() const override {
        double salary = basicPay + bonus;
        Logger::Log("Calculated salary for Permanent Employee: " + std::to_string(salary));
        return salary;
    }

    std::string GetDetails() const override {
        return "Permanent Employee: Basic Pay = " + std::to_string(basicPay) + ", Bonus = " + std::to_string(bonus);
    }
};

// Concrete Employee: Contract Employee
class ContractEmployee : public IEmployee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(double hourlyRate, int hoursWorked)
        : hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double CalculateSalary() const override {
        double salary = hourlyRate * hoursWorked;
        Logger::Log("Calculated salary for Contract Employee: " + std::to_string(salary));
        return salary;
    }

    std::string GetDetails() const override {
        return "Contract Employee: Hourly Rate = " + std::to_string(hourlyRate) + ", Hours Worked = " + std::to_string(hoursWorked);
    }
};

// Payroll Service
class PayrollService {
public:
    void GeneratePayroll(const std::vector<std::shared_ptr<IEmployee>>& employees) {
        Logger::Log("Generating payroll report...");
        for (const auto& employee : employees) {
            std::cout << employee->GetDetails() << std::endl;
            std::cout << "Salary: " << employee->CalculateSalary() << std::endl;
        }
        Logger::Log("Payroll generation complete.");
    }
};

// Example usage
int main() {
    // Create employees
    std::shared_ptr<IEmployee> permanentEmployee = std::make_shared<PermanentEmployee>(50000, 10000);
    std::shared_ptr<IEmployee> contractEmployee = std::make_shared<ContractEmployee>(200, 120);

    // Add employees to the list
    std::vector<std::shared_ptr<IEmployee>> employees = { permanentEmployee, contractEmployee };

    // Generate payroll
    PayrollService payrollService;
    payrollService.GeneratePayroll(employees);

    return 0;
}
