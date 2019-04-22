#pragma once
#include <iostream>
#include "Shop.h"

class ShopManager {
private:

public:
	Shop shop;
	ShopManager();
	void OpenShop(Player& player);
	~ShopManager();
};

