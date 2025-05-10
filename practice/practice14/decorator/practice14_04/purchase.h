//AI: used a bit more to help me understand the decorator a bit more. I was having trouble understanding. I also needed a bit more help with the organization in this one
#pragma once

#include <memory>

class Purchase {
public:
	virtual ~Purchase() = default;
	virtual double getCost() const = 0;
};

class SimplePurchase : public Purchase {
	double baseCost;
public:
	SimplePurchase(double cost);
	double getCost() const override;
};

class PurchaseDecorator : public Purchase {
protected:
	std::unique_ptr<Purchase> wrapped;
public:
	PurchaseDecorator(std::unique_ptr<Purchase> p) : wrapped(std::move(p)) {}
	virtual ~PurchaseDecorator() = default;
};

class TaxDecorator : public PurchaseDecorator {
public:
	TaxDecorator(std::unique_ptr<Purchase> p);
	double getCost() const override;
};

class ShippingFeeDecorator : public PurchaseDecorator {
	double fee;
public:
	ShippingFeeDecorator(std::unique_ptr<Purchase> p, double f = 5.0);
	double getCost() const override;
};

class DiscountDecorator : public PurchaseDecorator {
	double percent;
public:
	DiscountDecorator(std::unique_ptr<Purchase> p, double pct);
	double getCost() const override;
};