#pragma once
#include <vector>
// interfaces
#include "SellerProductInterface.h"
#include "SellerOrderInterface.h"
#include "SellerInformationInterface.h"
#include "BuyerProductInterface.h"
#include "BuyerOrderListInterface.h"
#include "BuyerInformationInterface.h"
// components
#include "Seller.h"
#include "Buyer.h"
#include "Product.h"
#include "Category.h"
#include "Order.h"
#include "Coupon.h"
#include "User.h"

class EleventhStreet : public SellerProductInterface, public SellerOrderInterface,
	public SellerInformationInterface, public BuyerProductInterface,
	public BuyerOrderListInterface, public BuyerInformationInterface
{
private:
	std::vector<Seller> seller_list;
	std::vector<Buyer> buyer_list;
	std::vector<Product> product_list;
	std::vector<Category> category_list;
	std::vector<Order> order_list;
	std::vector<Coupon> coupon_list;
	User* current_user;
	unsigned int  current_product_id;
	int select_number;
public:
	void log_in();
	void sign_in();

	// SellerProductInterface
	void display_product_details(const unsigned int& product_id) override;
	void display_seller_products() override;
	void modify_product_details() override;
	void delete_product() override;
	void add_product() override;
	void category_selection() override;
	void issue_coupon() override;
	void display_coupons() override;
	void delete_coupon() override;

	// SellerOrderInterface
	void set_status() override;
	void set_actual_order_date() override;
	void display_order() override;

	// SellerInformationInterface
	void display_seller_account_information() override;
	void modify_seller_account_information() override;

	// BuyerProductInterface
	void display_product_details(const unsigned int& product_id) override;
	void display_all_products() override;
	void display_option_selection_page() override;
	void display_coupon_available() override;
	void apply_coupon() override;
	void request_order(const Order& new_order) override;

	// BuyerOrderListInterface
	void display_buyer_order_list(const unsigned int& buyer_id) override;
	void display_item_details(const unsigned int& order_id) override;
	void request_order_refund(const unsigned int& order_id) override;
	void request_refund(const unsigned int& order_id,
		const unsigned int& item_index) override;

	// BuyerInformationInterface
	void display_buyer_account_information() override;
	void modify_buyer_account_information() override;
}