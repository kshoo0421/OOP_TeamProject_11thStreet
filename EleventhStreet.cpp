#include "EleventhStreet.h"

class EleventhStreet : public SellerMallInterface, public BuyerMallInterface
{
private:
	CategoryManager category_manager;
	std::vector<Seller*> seller_list;
	std::vector<Buyer*> buyer_list;
	std::vector<Product*> product_list;
	std::vector<Order*> order_list;
	std::vector<Coupon*> coupon_list;
public:
	EleventhStreet()
	{

	}

	~EleventhStreet()
	{

	}

	Seller* seller_log_in()
	{

	}

	Buyer* buyer_log_in()
	{

	}

	void seller_sign_in()
	{

	}

	void buyer_sign_in()
	{

	}

	// SellerMallInterface
	void add_coupon() override
	{

	}

	void display_coupons(const unsigned int& product_id) const override
	{

	}

	void delete_coupon(const unsigned int& coupon_id) override
	{

	}

	void display_main_categories() const override
	{
		category_manager.display_categories();
	}

	void display_sub_categories() const override
	{

	}

	void add_new_product(const Product& new_product) const override
	{

	}

	void display_orders_by_seller_id(const unsigned int& seller_id) const override
	{

	}

	Order* get_order(const unsigned int& order_id) const override
	{

	}

	Product* get_product(const unsigned int& product_id) const override
	{

	}
	// SellerMallInterface-SellerInterface
	void poster_product_list() override
	{

	}

	void requested_orders() override
	{

	}

	void my_information() override
	{

	}

	// BuyerMallInterface
	void display_all_products() override
	{

	}

	void request_order(Order* new_order) override
	{

	}

	void display_coupons(const unsigned int& product_id) override
	{
	}

	Coupon get_coupon(const unsigned int& coupon_id) const override
	{

	}

	void add_new_order() const override
	{

	}

	void display_orders_by_buyer_id(const unsigned int& buyer_id) const override
	{

	}

	Product* get_product(const unsigned int& product_id) override
	{
		
	}

	Order* get_order(const unsigned int& order_id) override
	{

	}

	// BuyerMallInterface - BuyerInterface
	void go_shopping() override
	{

	}

	void look_up_my_order_list() const override
	{

	}

	void my_information() const override
	{

	}
};