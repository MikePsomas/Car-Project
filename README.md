# Awesome Car Sales Program

Welcome to the Awesome Car Sales Program! This program simulates the car sales process in an office environment. It allows customers to buy cars, view sales statistics, and check sales data within a specific range. The program also supports discount eligibility based on age and customer card status.

## Features

- **Buy Cars**: Customers can buy cars based on availability and price.
- **View Sales Stats**: Customers can view the total sales made.
- **Subset of Sales Stats**: View sales stats between a specified minimum and maximum number of cars sold.
- **Discount Eligibility**: Customers between the ages of 18-30 receive a 20% discount. A customer card also grants a discount.
- **Sales Tracking**: Tracks the number of cars sold, car types, customer names, and whether a discount was given.
- **Data Persistence**: Sales data is stored in a CSV file (`data.csv`) for later access and analysis.

## How to Use

1. **Start the Program**:
   When you run the program, you will be greeted with the main menu where you can choose between different actions:
   - `a`: Buy a car.
   - `b`: View car sales stats.
   - `c`: View sales stats between a specific range of car sales.
   - `x`: Exit the program.

2. **Buying a Car**:
   - Enter your name.
   - Specify the number of cars you wish to buy.
   - Choose the type of car (from a list of available cars).
   - Enter your age to check if you are eligible for a discount.
   - If eligible, a 20% discount is applied to the total price.
   - The purchase is logged and the stock is updated.

3. **Viewing Sales Stats**:
   - View all sales or a subset of sales based on the number of cars sold.
   - Sales data includes: sale index, total sale amount, car type, number of cars, whether a discount was given, and the customer's name.

4. **Exiting the Program**:
   - The program will save all the sales data to `data.csv` before exiting.

## Data File

The program uses a CSV file (`data.csv`) to store sales information. The file stores the following data for each sale:
- Number of cars sold
- Car type
- Discount status
- Customer name

## Configuration

- **Minimum Age for Discount**: 18
- **Maximum Age for Discount**: 30
- **Discount Percentage**: 20%
- **Maximum Cars Available**: 10

## Requirements

- C Compiler (e.g., GCC)
- Operating System: Windows/Linux (the program detects and adapts to the environment)
- File path for CSV: `D:\\data.csv` (Ensure the file path exists or modify it to suit your system)

## License

This project is open-source. Feel free to use and modify it as you like.
