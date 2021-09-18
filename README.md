# CellphoneTyping
Cellphone Typing problem using suffix automaton

A research team is developing a new technology to save time when typing text messages in mobile devices. They are working on a new model that has a complete keyboard, so users can type any single letter by pressing the corresponding key. In this way, a user needs P keystrokes to type a word of length P.

However, this is not fast enough. The team is going to put together a dictionary of the common words that a user may type. The goal is to reduce the average number of keystrokes needed to type words that are in the dictionary. During the typing of a word, whenever the following letter is uniquely determined, the cellphone system will input it automatically, without the need for a keystroke. To be more precise, the behavior of the cellphone system will be determined by the following rules:

1. The system never guesses the first letter of a word, so the first letter always has to be input manually by pressing the corresponding key.

2. If a non-empty succession of letters c1c2...cn has been input, and there is a letter c such that every word in the dictionary which starts with c1c2...cn also starts with c1c2...cnc, then the system inputs c automatically, without the need of a keystroke. Otherwise, the system waits for the user.

For instance, if the dictionary is composed of the words "hello", "hell", "heaven" and "goodbye", and the user presses "h", the system will input "e" automatically, because every word which starts with "h" also starts with "he". However, since there are words that start with "hel" and with "hea", the system now needs to wait for the user. If the user then presses "l", obtaining the partial word "hel", the system will input a second "l" automatically. When it has "hell" as input, the system cannot guess, because it is possible that the word is over, or it is also possible that the user may want to press "o" to get "hello". In this fashion, to type the word "hello" the user needs three keystrokes, "hell" requires two, and "heaven" also requires two, because when the current input is "hea" the system can automatically input the remainder of the word by repeatedly applying the second rule. Similarly, the word "goodbye" needs just one keystroke, because after pressing the initial "g" the system will automatically fill in the entire word. In this example, the average number of keystrokes needed to type a word in the dictionary is then (3 + 2 + 2 + 1)/4 = 2.00.

Your task is, given a dictionary, to calculate the average number of keystrokes needed to type a word in the dictionary with the new cellphone system.

Input
Each test case is described using several lines. The first line contains an integer N representing the number of words in the dictionary (1 ≤ N ≤ 105 ). Each of the next N lines contains a non-empty string of at most 80 lowercase letters from the English alphabet, representing a word in the dictionary. Within each test case all words are diferent, and the sum of the lengths of all words is at most 106.

Output
For each test case output a line with a rational number representing the average number of keystrokes needed to type a word in the dictionary. The result must be output as a rational number with exactly two digits after the decimal point, rounded if necessary.
