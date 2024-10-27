#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate
#include <iterator> // For std::unique_copy

using namespace std;

int main() {
    vector<int> numbers = {5, 2, 9, 1, 5, 6, 2, 9, 4};

    // 1. std::sort
    sort(numbers.begin(), numbers.end());
    cout << "Sorted: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // 2. std::stable_sort
    stable_sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b; // Sort in descending order
    });
    cout << "Stable sorted (desc): ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // 3. std::partial_sort
    vector<int> partial = {5, 2, 9, 1, 5, 6, 2, 9, 4};
    partial_sort(partial.begin(), partial.begin() + 4, partial.end()); // Sort first 4 elements
    cout << "Partial sorted (first 4): ";
    for (int n : partial) cout << n << " ";
    cout << endl;

    // 4. std::nth_element
    nth_element(numbers.begin(), numbers.begin() + 3, numbers.end()); // Put 4th smallest element in correct position
    cout << "After nth_element: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // 5. std::copy
    vector<int> copied(numbers.size());
    copy(numbers.begin(), numbers.end(), copied.begin());
    cout << "Copied: ";
    for (int n : copied) cout << n << " ";
    cout << endl;

    // 6. std::transform
    vector<int> transformed(numbers.size());
    transform(numbers.begin(), numbers.end(), transformed.begin(), [](int x) {
        return x * 2; // Double each element
    });
    cout << "Transformed (doubled): ";
    for (int n : transformed) cout << n << " ";
    cout << endl;

    // 7. std::for_each
    cout << "For each element (original): ";
    for_each(numbers.begin(), numbers.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    // 8. std::find
    auto it = find(numbers.begin(), numbers.end(), 5);
    cout << (it != numbers.end() ? "Found 5!" : "5 not found.") << endl;

    // 9. std::find_if
    it = find_if(numbers.begin(), numbers.end(), [](int x) {
        return x > 6; // Find first element greater than 6
    });
    cout << (it != numbers.end() ? "Found an element > 6!" : "No element > 6 found.") << endl;

    // 10. std::count
    int count_of_5 = count(numbers.begin(), numbers.end(), 5);
    cout << "Count of 5: " << count_of_5 << endl;

    // 11. std::count_if
    int count_greater_than_5 = count_if(numbers.begin(), numbers.end(), [](int x) {
        return x > 5;
    });
    cout << "Count of elements > 5: " << count_greater_than_5 << endl;

    // 12. std::remove
    vector<int> to_remove = {1, 5, 2, 5, 3};
    auto new_end = remove(to_remove.begin(), to_remove.end(), 5);
    to_remove.erase(new_end, to_remove.end());
    cout << "After remove (5): ";
    for (int n : to_remove) cout << n << " ";
    cout << endl;

    // 13. std::remove_if
    vector<int> to_remove_if = {1, 2, 3, 4, 5, 6};
    new_end = remove_if(to_remove_if.begin(), to_remove_if.end(), [](int x) {
        return x % 2 == 0; // Remove even numbers
    });
    to_remove_if.erase(new_end, to_remove_if.end());
    cout << "After remove_if (even): ";
    for (int n : to_remove_if) cout << n << " ";
    cout << endl;

    // 14. std::unique
    vector<int> duplicates = {1, 1, 2, 3, 3, 4};
    new_end = unique(duplicates.begin(), duplicates.end());
    duplicates.erase(new_end, duplicates.end());
    cout << "After unique: ";
    for (int n : duplicates) cout << n << " ";
    cout << endl;

    // 15. std::unique_copy
   vector<int> unique_copy_vector(duplicates.size());
    auto unique_end = unique_copy(duplicates.begin(), duplicates.end(), unique_copy_vector.begin());
    unique_copy_vector.erase(unique_end, unique_copy_vector.end()); // Erase leftover default values
    cout << "Unique copy: ";
    for (int n : unique_copy_vector) cout << n << " ";
    cout << endl;
    // 16. std::accumulate
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of numbers: " << sum << endl;

    // 17. std::inner_product
    vector<int> b = {1, 2, 3, 4, 5};
    int inner_product_result = inner_product(numbers.begin(), numbers.end(), b.begin(), 0);
    cout << "Inner product: " << inner_product_result << endl;

    // 18. std::adjacent_find
    auto adjacent_it = adjacent_find(numbers.begin(), numbers.end());
    if (adjacent_it != numbers.end()) {
        cout << "First pair of equal elements: " << *adjacent_it << endl;
    } else {
        cout << "No adjacent equal elements found." << endl;
    }

    // 19. std::min_element
    auto min_it = min_element(numbers.begin(), numbers.end());
    cout << "Minimum element: " << *min_it << endl;

    // 20. std::max_element
    auto max_it = max_element(numbers.begin(), numbers.end());
    cout << "Maximum element: " << *max_it << endl;

    return 0;
}
