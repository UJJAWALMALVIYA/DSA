MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}


def is_sufficient_resource(order_ingredient):
    for item in order_ingredient:
        if order_ingredient[item] > resources[item]:
            print(f"Sorry , there is not enough {item}.")
            return False
    return True





def process_coin():
    print("Plz, insert a coins.")
    total = int(input("how many quauters ? "))*0.25
    total += int(input("how many dimes ? ")) * 0.1
    total += int(input("how many nickles ? ")) * 0.05
    total += int(input("how many pennis ? ")) * 0.01

    return total

def decrement(order_ingredients):

    for item in order_ingredients:
        resources[item] -= order_ingredients[item]


profit = 0


def is_transaction_successful( payments , drink_cost):
    if payments >= drink_cost:
        global profit
        profit += drink_cost
        change = round(payments-drink_cost, 2)
        print(f"this is your change ${change}")
        return True
    else:
        print("Sorry , that's not enough money")
        return False



is_on=True
while is_on:
    choice = input("What would you like ?(espresso/latte/cappuccino): ")
    if choice == "off":
        is_on = False
    elif choice == "report":
        print(f"water: {resources['water']}ml")
        print(f"milk : {resources['milk']}ml")
        print(f"coffee : {resources['coffee']}ml")
        print(f"Profit : ${profit}")
    else :
        drink = MENU[choice]
        # print(drink)
        if is_sufficient_resource(drink["ingredients"]) :
            payment = process_coin()
            if is_transaction_successful(payment,drink["cost"]):
                print(f"Here is your {choice}. Enjoy!☕.")
                decrement(drink["ingredients"])