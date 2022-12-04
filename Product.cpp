#include "Product.h"

class Product : public BuyerProductInterface, public SellerProductInterface, public ProductSearchInterface
{
private:
	unsigned int product_id;
	unsigned int seller_id;
	std::vector<Option> option_list;
	DeliveryDetails delivery_details;
	ProductDetails description;
public:
	// Buyer- �������̽� ����
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

	OrderItem option_selection() const override
	{
			
	}
	
	unsigned int get_main_price() override
	{
		return description.get_main_price();
	}

	// Seller- �������̽� ����
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

	// ProductSearch- �������̽� ����
	unsigned int get_product_id() const override
	{
		return product_id;
	}

	unsigned int get_seller_id() const override
	{
		return seller_id;
	}
};