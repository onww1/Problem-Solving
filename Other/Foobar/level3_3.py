class Math(object):
    @staticmethod
    def gcd(a, b):
        if not b:
            return a
        return Math.gcd(b, a % b)

    @staticmethod
    def lcm(a, b):
        return a // Math.gcd(a, b) * b


class Fraction(object):
    def __init__(self, numerator=0, denominator=1):
        if denominator == 0:
            raise ValueError("denominator shouldn't be zero.")
        gcd = Math.gcd(numerator, denominator)
        self.numerator = numerator // gcd
        self.denominator = denominator // gcd
        if self.denominator < 0:
            self.numerator *= -1
            self.denominator *= -1
        if self.numerator == 0:
            self.denominator = 1

    def __add__(self, other):
        lcm = Math.lcm(self.denominator, other.denominator)
        numerator = self.numerator * (lcm // self.denominator) + \
            other.numerator * (lcm // other.denominator)
        return Fraction(numerator, lcm)

    def __sub__(self, other):
        lcm = Math.lcm(self.denominator, other.denominator)
        numerator = self.numerator * (lcm // self.denominator) - \
            other.numerator * (lcm // other.denominator)
        return Fraction(numerator, lcm)

    def __mul__(self, other):
        return Fraction(self.numerator * other.numerator, self.denominator * other.denominator)

    def __div__(self, other):
        if other.numerator == 0:
            raise ValueError("divisor shouldn't be zero.")
        return Fraction(self.numerator * other.denominator, self.denominator * other.numerator)

    def __lt__(self, other):
        diff = self - other
        return diff.numerator < 0

    def __abs__(self):
        return Fraction(abs(self.numerator), self.denominator)

    def __repr__(self):
        ret = str(self.numerator)
        if self.denominator != 0:
            ret += '/'
            ret += str(self.denominator)
        return ret


class Matrix(object):
    def __init__(self, shape=(1, 1)):
        if shape[0] <= 0 or shape[1] <= 0:
            raise ValueError("matrix size should be positive.")
        self.shape = shape
        self.data = [[Fraction() for _ in range(shape[1])]
                     for _ in range(shape[0])]

    def __add__(self, other):
        if self.shape[0] != other.shape[0] or self.shape[1] != other.shape[1]:
            raise ValueError("two matrix size should be equal.")
        shape = self.shape
        ret = Matrix(shape=shape)
        for i in range(shape[0]):
            for j in range(shape[1]):
                ret.data[i][j] = self.data[i][j] + other.data[i][j]
        return ret

    def __sub__(self, other):
        if self.shape[0] != other.shape[0] or self.shape[1] != other.shape[1]:
            raise ValueError("two matrix size should be equal.")
        shape = self.shape
        ret = Matrix(shape=shape)
        for i in range(shape[0]):
            for j in range(shape[1]):
                ret.data[i][j] = self.data[i][j] - other.data[i][j]
        return ret

    def __mul__(self, other):
        if self.shape[1] != other.shape[0]:
            raise ValueError("two matrix size does not match.")
        shape, dim = (self.shape[0], other.shape[1]), self.shape[1]
        ret = Matrix(shape=shape)
        for i in range(shape[0]):
            for j in range(shape[1]):
                for k in range(dim):
                    ret.data[i][j] += self.data[i][k] * other.data[k][j]
        return ret

    def __repr__(self):
        ret = ""
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                ret += repr(self.data[i][j])
                ret += " "
            ret += "\n"
        return ret

    def set_element(self, row, col, value):
        if row < 0 or row >= self.shape[0] or col < 0 or col >= self.shape[1]:
            raise ValueError("Index Out-of-bound")
        self.data[row][col] = value

    @staticmethod
    def identity(size=1):
        shape = (size, size)
        ret = Matrix(shape=shape)
        for i in range(size):
            ret.data[i][i] = Fraction(1)
        return ret

    @staticmethod
    def determinant(matrix):
        if matrix.shape[0] != matrix.shape[1]:
            raise ValueError("matrix should be square.")
        size = matrix.shape[0]

        if size == 1:
            return matrix.data[0][0]
        if size == 2:
            return matrix.data[0][0] * matrix.data[1][1] - matrix.data[0][1] * matrix.data[1][0]

        det = Fraction(0)
        for start_col in range(size):
            partial_mul = Fraction(1)
            for row in range(size):
                col = (start_col + row) % size
                partial_mul *= matrix.data[row][col]
            det += partial_mul

            partial_mul = Fraction(1)
            for row in range(size):
                col = (size - 1 - start_col - row) % size
                partial_mul *= matrix.data[row][col]
            det -= partial_mul

        return det

    @staticmethod
    def copy(matrix):
        ret = Matrix(shape=matrix.shape)
        for i in range(matrix.shape[0]):
            for j in range(matrix.shape[1]):
                ret.set_element(i, j, Fraction(
                    matrix.data[i][j].numerator, matrix.data[i][j].denominator))
        return ret

    @staticmethod
    def inverse(matrix):
        if matrix.shape[0] != matrix.shape[1]:
            raise ValueError("matrix should be square.")
        det = Matrix.determinant(matrix)
        if det.numerator == 0:
            raise RuntimeError("matrix is not invertible.")

        size = matrix.shape[0]
        ret = Matrix.identity(size=size)

        matrix = Matrix.copy(matrix)
        for i in range(size):
            max_value = Fraction(-100000)
            max_index = None
            for row in range(i, size):
                value = matrix.data[row][i]
                if max_index is None or max_value < abs(value):
                    max_value = abs(value)
                    max_index = row

            if max_index != i:
                matrix.data[i], matrix.data[max_index] = matrix.data[max_index], matrix.data[i]
                ret.data[i], ret.data[max_index] = ret.data[max_index], ret.data[i]

            active_row = matrix.data[i]
            active_ret_row = ret.data[i]

            for row in range(i + 1, size):
                scale = matrix.data[row][i] / matrix.data[i][i]
                cur_row = matrix.data[row]
                cur_ret_row = ret.data[row]
                for col in range(size):
                    cur_row[col] -= scale * active_row[col]
                    cur_ret_row[col] -= scale * active_ret_row[col]

        for i in range(size - 1, -1, -1):
            active_row = matrix.data[i]
            active_ret_row = ret.data[i]
            for row in range(i, -1, -1):
                cur_row = matrix.data[row]
                cur_ret_row = ret.data[row]
                if row == i:
                    scale = active_row[i]
                    for col in range(size):
                        cur_row[col] /= scale
                        cur_ret_row[col] /= scale
                else:
                    scale = cur_row[i]
                    for col in range(size):
                        cur_row[col] -= scale * active_row[col]
                        cur_ret_row[col] -= scale * active_ret_row[col]
        return ret


def solution(m):
    size = len(m)
    M = Matrix(shape=(size, size))

    terminal_nodes = []
    for row in range(size):
        row_sum = 0
        for col in range(size):
            row_sum += m[row][col]

        if row_sum == 0:
            terminal_nodes.append(row)
            continue

        for col in range(size):
            if m[row][col] > 0:
                M.set_element(row, col, Fraction(m[row][col], row_sum))

    if 0 in terminal_nodes:
        answer = [0] * (len(terminal_nodes) - 1)
        answer = [1] + answer + [1]
        return answer

    q_size = size - len(terminal_nodes)
    Q = Matrix(shape=(q_size, q_size))
    I = Matrix.identity(size=q_size)
    R = Matrix(shape=(q_size, len(terminal_nodes)))

    rcnt = 0
    for row in range(size):
        ccnt = 0
        if row in terminal_nodes:
            rcnt += 1
            continue

        for col in range(size):
            if col in terminal_nodes:
                R.set_element(row - rcnt, ccnt, M.data[row][col])
                ccnt += 1
            else:
                Q.set_element(row - rcnt, col - ccnt, M.data[row][col])

    if q_size > 1:
        F = Matrix.inverse(I - Q)
        FR = F * R
    else:
        FR = R

    denominator = 1
    for col in range(FR.shape[1]):
        if FR.data[0][col].numerator == 0:
            continue
        denominator = Math.lcm(denominator, FR.data[0][col].denominator)

    answer = []
    for col in range(FR.shape[1]):
        if FR.data[0][col].numerator == 0:
            answer.append(0)
            continue
        scale = denominator // FR.data[0][col].denominator
        answer.append(FR.data[0][col].numerator * scale)
    answer.append(denominator)

    return answer


if __name__ == "__main__":
    m = [
        [0, 2, 1, 0, 0],
        [0, 0, 0, 3, 4],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ]
    ret = solution(m)
    print(ret)  # [7, 6, 8, 21]

    m = [
        [0, 1, 0, 0, 0, 1],
        [4, 0, 0, 3, 2, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    ret = solution(m)
    print(ret)  # [0, 3, 2, 9, 14]

    m = [
        [1, 2, 3, 0, 0, 0],
        [4, 5, 6, 0, 0, 0],
        [7, 8, 9, 1, 0, 0],
        [0, 0, 0, 0, 1, 2],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    ret = solution(m)
    print(ret)  # [1, 2, 3]

    m = [
        [0]
    ]
    ret = solution(m)
    print(ret)  # [1, 1]
