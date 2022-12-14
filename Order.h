#pragma once
#include <vector>
#include <windows.h>
#include <ctime>
#include "BuyerOrderInterface.h"
#include "SellerOrderInterface.h"
#include "SearchOrderInterface.h"
#include "OrderItem.h"
#include "Address.h"

enum Status
{
	order_requested, 
	products_prepared, 
	products_on_delivery,
	products_arriving,
	refund_requested,
	refunded,
	partial_refund_requested,
	patially_refunded
};

class Order : public BuyerOrderInterface, public SellerOrderInterface, public SearchOrderInterface
{
private :
	unsigned int order_id;
	unsigned int product_id;
	unsigned int buyer_id;
	std::vector<OrderItem> order_item_list;
	Address buyer_address;
	unsigned int order_date;
	unsigned int estimate_order_date;
	int actual_arrival_date;
	unsigned int delivery_fee;
	unsigned int total_product_price;
	unsigned int total_price;
	Status status;
public :
	Order(const unsigned int& input) : order_id(input) { };
	void clear_order_item_list();

	// Buyer- 
	void add_order_item(const OrderItem& new_item) override;
	void display_order_details() const override;
	void display_order() const override;
	void set_buyer_address(const Address& buyer_address) override;
	void set_delivery_price() override;
	void set_total_price() override;
	void set_total_product_price() override;

	// Seller- 
	void set_status() override;
	void set_actual_arrival_date() override;

	// Search-
	unsigned int get_order_id() const override;
};