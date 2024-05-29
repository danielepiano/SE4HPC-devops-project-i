#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/*
 * #####################################################################################################################
 * Testing matrix product.
 * A x B = C
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

/*
 * #####################################################################################################################
 * Testing scalar product.
 * a x b = ab
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestScalarProduct) {
    std::vector<std::vector<int>> A = {
            {7}
    };
    std::vector<std::vector<int>> B = {
            {5}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {35}
    };

    ASSERT_EQ(C, expected) << "Scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Commutative scalar product failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing 0-element property for scalar product.
 * 0 x b = 0
 * Includes: metamorphic relation to test commutative property and so 0-product for both factors A and B.
 * a x 0 = 0
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, Test0ElementScalarProduct) {
    std::vector<std::vector<int>> A = {
            {0}
    };
    std::vector<std::vector<int>> B = {
            {7}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {0}
    };

    ASSERT_EQ(C, expected) << "0-element property (left 0) for scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "0-element property (right 0) for scalar product failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing neutral element property for scalar product.
 * 1 x b = b
 * Includes: metamorphic relation to test commutative property and so 1-product for both factors A and B.
 * a x 1 = a
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestNeutralElementScalarProduct) {
    std::vector<std::vector<int>> A = {
            {1}
    };
    std::vector<std::vector<int>> B = {
            {7}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {7}
    };

    ASSERT_EQ(C, expected) << "Neutral element property (left 1) for scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Neutral element property (right 1) for scalar product failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing associative property for scalar product.
 * a x b x c = (a x b) x c = a x (b x c) = (a x c) x b = abc = d
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestAssociativePropertyScalarProduct) {
    std::vector<std::vector<int>> A = {
            {2}
    };
    std::vector<std::vector<int>> B = {
            {3}
    };
    std::vector<std::vector<int>> C = {
            {4}
    };

    std::vector<std::vector<int>> D_temp(1, std::vector<int>(1, 0));
    std::vector<std::vector<int>> D1(1, std::vector<int>(1, 0));
    std::vector<std::vector<int>> D2(1, std::vector<int>(1, 0));
    std::vector<std::vector<int>> D3(1, std::vector<int>(1, 0));

    // D1 = (A x B) x C
    multiplyMatrices(A, B, D_temp, 1, 1, 1);
    multiplyMatrices(D_temp, C, D1, 1, 1, 1);

    // D2 = A x (B x C)
    multiplyMatrices(B, C, D_temp, 1, 1, 1);
    multiplyMatrices(A, D_temp, D2, 1, 1, 1);

    // D3 = (A x C) x B
    multiplyMatrices(A, C, D_temp, 1, 1, 1);
    multiplyMatrices(D_temp, B, D3, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {24}
    };

    ASSERT_EQ(D1, expected) << "Associative property ((A x B) x C) for scalar product failed! :(((((";
    ASSERT_EQ(D2, expected) << "Associative property (A x (B x C)) for scalar product failed! :(((((";
    ASSERT_EQ(D3, expected) << "Associative property ((A x C) x B) for scalar product failed! :(((((";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
