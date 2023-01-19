import turtle as t
import random


screen = t.Screen()
screen.bgcolor("#BFEAF5")
screen.setup(500, 400)
is_race_start = False
colors=["red", "pink", "green", "blue", "black"]
user_bet = screen.textinput(title="Make your bet", prompt="which turtle will win the race ? (red / blue "
                                                          "/pink "
                                                          "/black "
                                                          "/ green) Enter a color: ")
y_pos = [-80, -40, 0, 40, 80, 120]
all_tur = []
for tur in range(0, 5):

    tim = t.Turtle(shape="turtle")
    tim.color(colors[tur])
    tim.penup()
    tim.goto(x=-230, y=y_pos[tur])
    all_tur.append(tim)

if user_bet in colors:
    is_race_start = True

while is_race_start:


    for turtle in all_tur:
        if turtle.xcor() > 230:
            is_race_start = False
            winner_col = turtle.pencolor()
            if winner_col == user_bet:
                print("You win !! ")
            else:
                print(f"You've lost !! The {winner_col} turtle is the winner ")
            break

        distance = random.randint(0, 10)
        turtle.forward(distance)






screen.exitonclick()