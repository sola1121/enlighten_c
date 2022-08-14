length = 11


class Solution():

    def last_one(self, start, appoint, length) -> int:
        pos = start
        for i in range(1, length + 1):
            pos = (pos + appoint) % i

        return pos


if __name__ == "__main__":

    solution = Solution()
    ret = solution.last_one(2, 3, length)
    print("最后结果: ", ret)