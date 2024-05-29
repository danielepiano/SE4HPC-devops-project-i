#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using IntMx = std::vector<std::vector<int>>;

class ScalarMultiplicationTestFixture :
public ::testing::TestWithParam<int> {
};
INSTANTIATE_TEST_SUITE_P(
        PositiveScalarRange,
        ScalarMultiplicationTestFixture,
        testing::Range(1, 150)
);
INSTANTIATE_TEST_SUITE_P(
        NegativeScalarRange,
        ScalarMultiplicationTestFixture,
        testing::Range(-150, -1)
);
INSTANTIATE_TEST_SUITE_P(
        ZeroScalarValue,
        ScalarMultiplicationTestFixture,
        testing::Values(0)
);

/*
 * #####################################################################################################################
 * WHAT
 * - Zero-element property for scalar multiplication.
 * HOW
 * - Parameterized test for ranges of values:
 *  * [-150, -1]
 *  * 0
 *  * [1, 150]
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
 * - Parameterized test for ranges of values:
 *  * [-150, -1]
 *  * 0
 *  * [1, 150]
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

    ASSERT_EQ(C, expected) << "Neutral element property (left 1) for scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Neutral element property (right 1) for scalar product failed! :(((((";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
