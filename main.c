#include <stdio.h>

// Structure definition for Order
struct Order {
    int orderId;
    char customerName[50];
    char productName[50];
    int quantity;
    float totalCost;
};

// Function to load orders from "orders.txt" file
void loadOrders(struct Order *orders, int size) {
    FILE *file = fopen("orders.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < size; i++) {
            fscanf(file, "%d %49s %49s %d %f", &orders[i].orderId, orders[i].customerName,
                   orders[i].productName, &orders[i].quantity, &orders[i].totalCost);
        }
        fclose(file);
        printf("Orders loaded successfully.\n");
    } else {
        printf("Error opening file for reading.\n");
    }
}

// Function to input order data from users and save to "orders.txt" file
void inputOrderData(struct Order *order) {
    printf("Enter Order ID: ");
    scanf("%d", &order->orderId);
    
    printf("Enter Customer Name: ");
    scanf("%s", order->customerName);

    printf("Enter Product Name: ");
    scanf("%s", order->productName);

    printf("Enter Quantity: ");
    scanf("%d", &order->quantity);

    printf("Enter Total Cost: ");
    scanf("%f", &order->totalCost);

    FILE *file = fopen("orders.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %s %s %d %.2f\n", order->orderId, order->customerName,
                order->productName, order->quantity, order->totalCost);
        fclose(file);
        printf("Order saved successfully.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

// Function to calculate total cost for each order
void calculateTotalCost(struct Order *orders, int size) {
    for (int i = 0; i < size; i++) {
        orders[i].totalCost = orders[i].quantity * orders[i].totalCost;
    }
}

// Function to display orders
void displayOrders(struct Order *orders, int size) {
    printf("%-10s%-20s%-20s%-10s%-15s\n", "Order ID", "Customer Name", "Product Name", "Quantity", "Total Cost");
    for (int i = 0; i < size; i++) {
        printf("%-10d%-20s%-20s%-10d%-15.2f\n", orders[i].orderId, orders[i].customerName,
               orders[i].productName, orders[i].quantity, orders[i].totalCost);
    }
}

int main() {
    struct Order orders[30];

    // Uncomment the line below to load orders from "orders.txt" file
    // loadOrders(orders, 30);

    // Input order data for each order
    for (int i = 0; i < 30; i++) {
        printf("\nEnter details for Order %d:\n", i + 1);
        inputOrderData(&orders[i]);
    }

    // Calculate total cost for each order
    calculateTotalCost(orders, 30);

    // Display orders
    displayOrders(orders, 30);

    return 0;
}
