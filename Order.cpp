#include "Order.h"
#include <windows.h>
using namespace std;

class Order : public BuyerOrderInterface, public SellerOrderInterface, public SearchOrderInterface
{
private:
	unsigned int order_id;
	unsigned int product_id;
	unsigned int buyer_id;
	std::vector<OrderItem> order_item_list;
	Address buyer_address;
	const unsigned int order_date = 1;	// const라서 넣은 임시값. 수정 필요
	const unsigned int estimate_order_date = 1;	// const라서 넣은 임시값. 수정 필요
	int actual_arrival_date;
	unsigned int delivery_fee;
	unsigned int total_product_price;
	unsigned int total_price;
	Status status;
public:
	Order(const unsigned int& input) : order_id(input) { }

	// Buyer- 
	void add_order_item(const OrderItem& new_item) override
	{
		order_item_list.push_back(new_item);
		cout << order_item_list.size() << "개의 제품이 장바구니에 담겨있습니다." << endl;
		return;
	}

	void display_order_details() const override
	{
		if (order_item_list.size() == 0)
		{
			cout << "주문하신 상품이 없습니다." << endl;
			return;
		}
		for (int i = 0; i < order_item_list.size(); i++)
		{
			cout << i + 1 << "번 상품" << endl;
			order_item_list[i].display_order_item();
		}
		return;
	}

	void display_order() const override
	{
		display_order_details();
		cout << "배송지 주소" << buyer_address.get_address_name() << endl;
		cout << "주문시간 :" << order_date << "예상 배송시간 :" << estimate_order_date << endl;
		cout << "제품 금액:" << total_product_price << endl;
		cout << "총 금액:" << total_price << endl;

		return;
	}

	void set_buyer_address(const Address& buyer_address_in) override
	{
		buyer_address = buyer_address_in;
		return;
	}

	void set_delivery_price() override
	{
		delivery_fee = total_product_price < 10000 ? 3000 : (total_product_price < 30000 ? 2500 : 0);
		return;
	}

	void set_total_price() override
	{
		total_price = total_product_price + delivery_fee;
		return;
	}

	void set_total_product_price() override
	{
		total_product_price = 0;
		vector<OrderItem>::iterator iterator = order_item_list.begin();
		for (; iterator < order_item_list.end(); iterator++)
			total_product_price += iterator->get_price() * iterator->get_quantity();
	}

	// Seller- 
	void set_status() override
	{
		int i = 0;
		cout << "주문 진행 상태를 입력해주세요" << endl;
		cout << "1. order_requested" << endl;
		cout << "2. products_prepared" << endl;
		cout << "3. products_on_delivery" << endl;
		cout << "4. products_arriving" << endl;
		cin >> i;
		status = Status(i - 1);
		return;

	}

	void set_actual_arrival_date() override
	{
		cout << "실제 배송기간을 입력해주세요" << endl;
		cin >> actual_arrival_date;
		return;
	}

	// Search-
	unsigned int get_order_id() const override
	{
		return order_id;
	}
};
