#pragma once
#include <vector>
#include "BuyerProductInterface.h"
#include "SellerProductInterface.h"
#include "ProductSearchInterface.h"
#include "Option.h"
#include "DeliveryDetails.h"
#include "ProductDetails.h"

class Product : public BuyerProductInterface, public SellerProductInterface, public ProductSearchInterface
{
private :
	unsigned int product_id;
	unsigned int seller_id;
	std::vector<Option> option_list;
	DeliveryDetails delivery_details;
	ProductDetails description;
public :
	Product();
	~Product();

	// Buyer- 인터페이스 내용
	void display_product_details(const unsigned int& product_id) override;
	unsigned int get_lead_time() const override;
	unsigned int get_free_delivery_amount() const override;
	unsigned int get_delivery_fee() const override;
	std::string option_selection(std::string& order_item_string,
		const unsigned int& order_item_price) override;
	unsigned int get_main_price() override;

	// Seller- 인터페이스 내용
	void display_product_details() const override;
	void modify_product() override;

	// ProductSearch- 인터페이스 내용
	std::string get_product_id() const override;
	std::string get_seller_id() const override;
};