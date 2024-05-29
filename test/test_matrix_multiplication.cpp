#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class IdentityScalarTest :
        public testing::TestWithParam<int> {
};
INSTANTIATE_TEST_SUITE_P(
        PositiveScalarRange,
        IdentityScalarTest,
        ::testing::Range(1, 150),
        );
INSTANTIATE_TEST_SUITE_P(
        NegativeScalarRange,
        IdentityScalarTest,
        ::testing::Range(-150, -1),
);
INSTANTIATE_TEST_SUITE_P(
        ZeroScalarValue,
        IdentityScalarTest,
        ::testing::Values(0),
);

/*
 * #####################################################################################################################
 * Testing neutral element property for scalar product.
 * Parameterized test for ranges of values:
 *  - [-150, -1]
 *  - 0
 *  - [1, 150]
 *  Includes: commutative property metamorphic relation.
 * #####################################################################################################################
 */
TEST_P(IdentityScalarTest, IdentityScalarTest) {
    int value = GetParam();

    std::vector<std::vector<int>> A = {
            {1}
    };
    std::vector<std::vector<int>> B = {
            {value}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
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
