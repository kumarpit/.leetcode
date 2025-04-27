# Write a class that, when given a string, will return an uppercase string with each letter shifted forward in the alphabet by however many spots the cipher was initialized to.
# If something in the string is not in the alphabet (e.g. punctuation, spaces), simply leave it as is.

class CaesarCipher:
    def __init__(self, shift: int):
        self.shift = shift;

    def encode(self, value: str) -> str:
        encoded = ''
        for char in value.upper():
            if char.isalpha():
                shifted = ((ord(char) - ord('A') + self.shift) % 26) + ord('A')
                encoded += chr(shifted)
            else:
                encoded += char

        return encoded

    def decode(self, value: str) -> str:
        decoded = ''
        for char in value:
            unshifted = ((ord(char) - ord('A') - self.shift) % 26) + ord('A')
            decoded += chr(unshifted)

        return decoded
