#pragma once
#include <string>
#include <vector>
#include "BuyerProductInterface.h"
#include "SellerProductInterface.h"
#include "ProductSearchInterface.h"
#include "ProductDetails.h"

static unsigned int product_index = 1001;

class Product : public BuyerProductInterface, public SellerProductInterface, public ProductSearchInterface
{
private :
	std::string product_name;
	unsigned int product_id;
	unsigned int seller_id;
	class ProductDetails* description;

	void init_product_set();
public :
	Product();
	Product(unsigned int seller_id_input);
	~Product();

	std::string get_product_name() const;
	enum class MainCategory get_category() const;

	// Buyer- 인터페이스 내용
	unsigned int get_main_price() override;

	// Seller- 인터페이스 내용
	void display_product_details() const override;
	void modify_product() override;

	// ProductSearch- 인터페이스 내용
	unsigned int get_product_id() const override;
	unsigned int get_seller_id() const override;
};