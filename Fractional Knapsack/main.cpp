#include <iostream>
#include<algorithm>
using namespace std;

struct item {
	double value, weight;
	double ratio;

	item() {}
	item(double v, double w , double r) {
		this->value = v;
		this->weight = w;
		this->ratio = r;
	}
};

bool cmp(struct item a, struct item b) {
	return a.ratio > b.ratio;
}

double knapsack(double w, struct item items[] , int n) {
	sort(items, items+n, cmp);
	double weight = 0;
	double value = 0.0;

	for (int i = 0; i <= n; i++) {
		if (weight + items[i].weight <= w) {
			weight += items[i].weight;
			value += items[i].value;
		}
		else {
			double remain = w - weight;
			value += items[i].value * (remain / items[i].weight);
			break;
		}
	}

	return value;
}

int main()
{
	cout << "max weight of knapsack : ";
	int w=0;
	cin >> w;
	cout << "number of items : ";
	int n=0;
	cin >> n;
	item itm[100];
	double wgt, val, rat;

	for (int i = 0; i < n; i++) {

		cout << "enter value of item number " << i + 1 << ": ";
		cin >> val;

		cout << "enter weight of item number " << i + 1<< ": " ;
		cin >> wgt;

		rat = val / wgt;

		itm[i] =  {val,wgt,rat };
	}


	cout << "Maximum value = "	<< knapsack(w, itm, n);

		return 0;
}

