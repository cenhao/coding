class ValidWordAbbr:
    def __init__(self, dictionary):
        """
        :type dictionary: List[str]
        """
        self.dict = {}
        for w in dictionary:
            key = w[0]+str(len(w)-2)+w[-1] if len(w) > 2 else w
            if key in self.dict and self.dict[key] != w:
                self.dict[key] = ""
            else:
                self.dict[key] = w

    def isUnique(self, word):
        """
        :type word: str
        :rtype: bool
        """
        key = word[0] + str(len(word)-2) + word[-1] if len(word) > 2 else word
        return (key not in self.dict) or (self.dict[key] == word)
        


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
