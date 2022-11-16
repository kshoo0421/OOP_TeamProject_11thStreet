#pragma once
#include <vector>
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
	std::vector<OrderItem> order_item_list;	// DynamicArray 대체
	Address buyer_address;
	const int order_date;	// time 대체
	int actual_arrival_date;	// time 대체
	unsigned int delivery_fee;
	unsigned int total_product_price;
	unsigned int total_discount_amount;
	unsigned int total_price;
	Status status;
public :
	Order();
	~Order();
};