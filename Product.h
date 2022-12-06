#pragma once
#include <vector>
#include "BuyerProductInterface.h"
#include "SellerProductInterface.h"
#include "ProductSearchInterface.h"
#include "DeliveryDetails.h"
#include "ProductDetails.h"
#include "CategoryManager.h"

class Product : public BuyerProductInterface, public SellerProductInterface, public ProductSearchInterface
{
private :
	CategoryManager category_manager;
	std::string product_name;
	unsigned int product_id;
	unsigned int seller_id;
	DeliveryDetails delivery_details;
	ProductDetails description;
public :
	void set_product_name();
	std::string get_product_name() const;
	MainCategory get_category() const;

	// Buyer- 인터페이스 내용
	void display_products_details() const override;
	std::string get_lead_time() const override;
	unsigned int get_free_delivery_amount() const override;
	unsigned int get_delivery_fee() const override;
	unsigned int get_main_price() override;

	// Seller- 인터페이스 내용
	void display_product_details() const override;
	void modify_product() override;

	// ProductSearch- 인터페이스 내용
	unsigned int get_product_id() const override;
	unsigned int get_seller_id() const override;
};