#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1602;

tuple<Node *, int> testFixture1()
{
  auto tree = new Node(1);
  tree->left = new Node(2);
  tree->left->right = new Node(4);
  tree->right = new Node(3);
  tree->right->left = new Node(5);
  tree->right->right = new Node(6);
  return make_tuple(tree, 4);
}

tuple<Node *, int> testFixture2()
{
  auto tree = new Node(3);
  tree->right = new Node(4);
  tree->right->left = new Node(2);

  return make_tuple(tree, 2);
}

tuple<Node *, int> testFixture3()
{
  auto tree = new Node(1);

  return make_tuple(tree, 1);
}

void test1()
{
  auto fixture = testFixture1();

  cout << "Test 1 - expect to see 5";

  Solution sol;
  auto node = sol.nextRight(get<0>(fixture), get<1>(fixture));

  string result = node != nullptr ? to_string(node->val) : "null";

  cout << "Test 1 - expect to see 5" << endl;

  cout << "result: " << result << endl;
}

void test2()
{
  auto fixture = testFixture2();

  cout << "Test 1 - expect to see 5";

  Solution sol;
  auto node = sol.nextRight(get<0>(fixture), get<1>(fixture));

  string result = node != nullptr ? to_string(node->val) : "null";

  cout << "Test 2 - expect to see null" << endl;

  cout << "result: " << result << endl;
}

void test3()
{
  auto fixture = testFixture3();

  cout << "Test 3 - expect to see null";

  Solution sol;
  auto node = sol.nextRight(get<0>(fixture), get<1>(fixture));

  string result = node != nullptr ? to_string(node->val) : "null";

  cout << "Test 1 - expect to see 5" << endl;

  cout << "result: " << result << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}