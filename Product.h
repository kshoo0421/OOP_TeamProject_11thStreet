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
	void display_products_details() const override;
	std::string get_lead_time() const override;
	unsigned int get_free_delivery_amount() const override;
	unsigned int get_delivery_fee() const override;
	OrderItem option_selection() const override;
	unsigned int get_main_price() override;

	// Seller- 인터페이스 내용
	void display_product_details() const override;
	void modify_product() override;
	void delete_product(const Product& product) override;
	void add_product(const Product& product) override;
	void category_selection() override;

	// ProductSearch- 인터페이스 내용
	unsigned int get_product_id() const override;
	unsigned int get_seller_id() const override;
};