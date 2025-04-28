NUM_TRIES = 5
WORD = "purse".upper()

def game_loop():
    # str -> list(int)
    # maps letters in the target word to their positions in the word
    char_to_positions = {}
    for index, char in enumerate(WORD):
        if not char in char_to_positions:
            char_to_positions[char] = [index]
        else:
            char_to_positions[char].append(index)

    for i in range(0, NUM_TRIES):
        guess = input(f"> Enter your guess ({NUM_TRIES - i} attempts remaining): ").upper()
        if guess == WORD:
            print("Congratulations, you guessed the word!")
        else:
            for index, char in enumerate(guess):
                if char in char_to_positions:
                    if index in char_to_positions[char]:
                        print(f"{char} is in the right position")
                    else:
                        print(f"{char} does appear, but not in this position")
                else:
                    print(f"{char} does not appear in the target word")



game_loop()
