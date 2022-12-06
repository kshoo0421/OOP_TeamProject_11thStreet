#include "Product.h"

class Product : public BuyerProductInterface, public SellerProductInterface, public ProductSearchInterface
{
private:
	std::string product_name;
	unsigned int product_id;
	unsigned int seller_id;
	DeliveryDetails delivery_details;
	ProductDetails description;
public:
	void set_product_name()
	{
		std::cout << "상품 이름을 결정하세요 : ";
		std::cin >> product_name;
		std::cout << "상품 이름이 " << product_name << "으로 결정되었습니다.\n";
		return;
	}

	std::string get_product_name() const
	{
		return product_name;
	}

	MainCategory get_category() const
	{
		description.get_category();
	}

	// Buyer- 인터페이스 내용
	void display_products_details() const override
	{
		description.display_details();
		return;
	}

	std::string get_lead_time() const override
	{
		return delivery_details.get_lead_time();
	}

	unsigned int get_free_delivery_amount() const override
	{
		return delivery_details.get_free_delivery_amount();
	}
	
	unsigned int get_delivery_fee() const override
	{
		return delivery_details.get_delivery_fee();
	}

	unsigned int get_main_price() override
	{
		return description.get_main_price();
	}

	// Seller- 인터페이스 내용
	void display_product_details() const override
	{
		description.display_details();
		return;
	}

	void modify_product() override
	{
		description.modify_details();
		return;
	}

	// ProductSearch- 인터페이스 내용
	unsigned int get_product_id() const override
	{
		return product_id;
	}

	unsigned int get_seller_id() const override
	{
		return seller_id;
	}
};