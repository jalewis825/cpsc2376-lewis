//AI: I thought i needed wrapped to be private and I struggle on taxdecorator. Used ai to figure out use protected instead
#include "purchase.h"

SimplePurchase::SimplePurchase(double cost) : baseCost(cost) {}

double SimplePurchase::getCost() const {
	return baseCost;
}

TaxDecorator::TaxDecorator(std::unique_ptr<Purchase> p) 
	: PurchaseDecorator(std::move(p)) {}

double TaxDecorator::getCost() const {
	return wrapped->getCost() * 1.10;
}

ShippingFeeDecorator::ShippingFeeDecorator(std::unique_ptr<Purchase> p, double f)
	: PurchaseDecorator(std::move(p)), fee(f) {}

double ShippingFeeDecorator::getCost() const {
	return wrapped->getCost() + fee;
}

DiscountDecorator::DiscountDecorator(std::unique_ptr<Purchase> p, double pct)
	: PurchaseDecorator(std::move(p)), percent(pct) {}

double DiscountDecorator::getCost() const {
	return wrapped->getCost() * (1.0 - percent);
}
