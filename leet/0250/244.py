'''
class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.hm = {}
        for w in words:
            if w not in self.hm:
                self.hm[w] = len(self.hm)

        self.dist = [[-1 for j in xrange(len(self.hm))] for i in xrange(len(self.hm))]

        for i in xrange(len(words)):
            for j in xrange(i+1, len(words)):
                idx1, idx2 = self.hm[words[i]], self.hm[words[j]]
                if idx1 == idx2: break
                if self.dist[idx1][idx2] < 0 or self.dist[idx1][idx2] > j-i:
                    self.dist[idx1][idx2] = self.dist[idx2][idx1] = j-i

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        return self.dist[self.hm[word1]][self.hm[word2]]
'''

class WordDistance(object):

    def __init__(self, words):
        """ 
        :type words: List[str]
        """
        self.hm = {}
        for i, w in enumerate(words):
            if w in self.hm:
                self.hm[w].append(i)
            else:
                self.hm[w] = [i]

    def shortest(self, word1, word2):
        """ 
        :type word1: str
        :type word2: str
        :rtype: int
        """
        arr1, arr2 = self.hm[word1], self.hm[word2]
        ans = 0x7fffffff
        i, j, l1, l2 = 0, 0, len(arr1), len(arr2)

        while i < l1 and j < l2:
            ans = min(ans, abs(arr1[i]-arr2[j]))
            if arr1[i] < arr2[j]:
                i += 1
            else:
                j += 1

        return ans

# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
