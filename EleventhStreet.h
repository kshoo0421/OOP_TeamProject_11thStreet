#pragma once
#include <vector>
// components
#include "CategoryManager.h"
#include "Product.h"
#include "Seller.h"
#include "Buyer.h"
#include "Order.h"
#include "User.h"
#include "ProductManager.h"

// interfaces
#include "SellerMallInterface.h"
#include "BuyerMallInterface.h"

class EleventhStreet : public SellerMallInterface, public BuyerMallInterface
{
private:
	CategoryManager category_manager;
	ProductManager product_manager;
	User cur_user;
	int cur_user_index;
	bool is_logined = false;
	bool is_user_seller = false;
	Seller seller_list[3];
	Buyer buyer_list[3];
	vector<Order> order_list;

	void use_eleventh_street();
	void use_seller_interface();
	void display_seller_interface();
	void use_buyer_interface();
	void display_buyer_interface();
	void display_shopping_options();
	void log_in();
	void log_out();
	Seller& seller_log_in();
	Buyer& buyer_log_in();
	void set_ids_and_orders();
	void buyer_address_control();
	Product register_new_product() const;

	// SellerMallInterface
	void display_categories() const override;
	void add_new_product(const Product& new_product) override;
	Order get_order(const unsigned int& order_id) const override;

	// SellerMallInterface-SellerInterface
	void register_product() override;

	// BuyerMallInterface
	void display_all_products() override;
	void request_order(Order new_order) override;
	void add_new_order() override;

	// BuyerMallInterface - BuyerInterface
	void go_shopping() override;
	void look_up_my_order_list() const override;
	void my_information() override;
	void display_orders_by_buyer_id() const;
	Order get_order() override;

public:
	EleventhStreet();
};