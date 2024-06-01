#include "matrix_multiplication.h"
#include <iostream>
#include <gtest/gtest.h>

using IntMx = std::vector<std::vector<int>>;

class ScalarMultiplicationTestFixture :
public testing::TestWithParam<int> {
};
INSTANTIATE_TEST_SUITE_P(
        IntegerScalarRange,
        ScalarMultiplicationTestFixture,
        testing::Range(-150, 150)
);

/*
 * #####################################################################################################################
 * WHAT
 * - Zero-element property for scalar multiplication.
 * HOW
 * - Parameterized test for ranges of values [-150, 150].
 * - Exploiting commutative property.
 * EXPECTED
 * - Result should be 0.
 * #####################################################################################################################
 */
TEST_P(ScalarMultiplicationTestFixture, WhenScalarX0ShouldBeZero) {
    int value = GetParam();

    IntMx A = {
            {0}
    };
    IntMx B = {
            {value}
    };

    IntMx C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    IntMx expected = {
            {0}
    };

    ASSERT_EQ(C, expected) << "Zero-element property (left 0) for scalar multiplication failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Zero-element property (right 0) for scalar multiplication failed! :(((((";
}

/*
 * #####################################################################################################################
 * WHAT
 * - Neutral-element property for scalar multiplication.
 * HOW
 * - Parameterized test for ranges of values [-150, 150].
 * - Exploiting commutative property.
 * EXPECTED
 * - Result should be equal to the factor <> neutral element.
 * #####################################################################################################################
 */
TEST_P(ScalarMultiplicationTestFixture, WhenScalarX1ShouldBeScalar) {
    int value = GetParam();

    IntMx A = {
            {1}
    };
    IntMx B = {
            {value}
    };

    IntMx C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    IntMx expected = {
            {value}
    };

    ASSERT_EQ(C, expected) << "Neutral element property (left 1) for scalar multiplication failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Neutral element property (right 1) for scalar multiplication failed! :(((((";
}

/*
 *
 * #####################################################################################################################
 * WHAT
 * - Scalar power of 2.
 * HOW
 * - Parameterized test for ranges of values [-150, 150].
 * EXPECTED
 * - Result should be equal to the actual value raised to the power of 2.
 * #####################################################################################################################
 */
TEST_P(ScalarMultiplicationTestFixture, WhenScalarXScalarShouldBePow2) {
    int value = GetParam();

    IntMx A = {
            {value}
    };
    IntMx B = {
            {value}
    };

    IntMx C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    IntMx expected = {
            {value * value}
    };

    ASSERT_EQ(C, expected) << "Scalar multiplication between equal numbers failed! :(((((";
}

/*
 *
 * #####################################################################################################################
 * WHAT
 * - Scalar product (row-column).
 * HOW
 * - Parameterized test for ranges of values [-150, 150].
 * EXPECTED
 * - Result should be equal to {num.elements} times the value squared.
 * #####################################################################################################################
 */
TEST_P(ScalarMultiplicationTestFixture, WhenScalarProductShouldBeSumOfSquaredValues) {
    int value = GetParam();

    IntMx A = {
            {value, value}
    };
    IntMx B = {
            {value},
            {value}
    };

    IntMx C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 2, 1);

    IntMx expected = {
            {2 * value * value}
    };

    ASSERT_EQ(C, expected) << "Scalar product (row-column) between equal vectors failed! :(((((";
}


/*
 * #####################################################################################################################
 * This test is the given example.
 * WHAT
 * - Testing matrix product.
 * EXPECTED
 * - Actual product.
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
            {1, 2, 3},
            {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
            {7, 8},
            {9, 10},
            {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
            {58, 64},
            {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
