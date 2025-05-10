#include "purchase.h"
#include <iostream>

int main()
{
	double baseCost;
	std::cout << "Enter base purchse amount: $";
	std::cin >> baseCost;

	std::unique_ptr<Purchase> purchase = std::make_unique<SimplePurchase>(baseCost);

	char applyTax;
	char applyShipping;
	char applyDiscount;

	std::cout << "Apply 10% tax? (y/n): ";
	std::cin >> applyTax;
	if (applyTax == 'y' || applyTax == 'Y') {
		purchase = std::make_unique<TaxDecorator>(std::move(purchase));
	}

	std::cout << "Apply $5 shipping fee? (y/n): ";
	std::cin >> applyShipping;
	if (applyShipping == 'y' || applyShipping == 'Y') {
		purchase = std::make_unique<ShippingFeeDecorator>(std::move(purchase), 5.0);
	}

	std::cout << "Apply discount? (y/n): ";
	std::cin >> applyDiscount;
	if (applyDiscount == 'y' || applyDiscount == 'Y') {
		double discountPercent;
		std::cout << "Enter discount percentage: ";
		std::cin >> discountPercent;
		purchase = std::make_unique<DiscountDecorator>(std::move(purchase), discountPercent/100.0);
	}

	std::cout << "Final purchase cost: $" << purchase->getCost() << std::endl;
}

