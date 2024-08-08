#include <gtest/gtest.h>
#include "Lottery.h"

// Fixture for the Lottery class
class LotteryTest : public ::testing::Test {
protected:
    Lottery lottery;  

    // Setup method to initialize the lottery object
    void SetUp() override {
        srand(0); // Seed random number generator for reproducibility
    }
};

// Test that the constructor properly initializes the volatilit vectors
TEST_F(LotteryTest, ConstructorInitializesVolatilit) {
    for (int col = 0; col < Lottery::NR_COLUMN; ++col) {
        int expectedSum = 0;
        for (int sym = 0; sym < Lottery::NR_SYMBOLS; ++sym) {
            expectedSum += lottery.volatilitTab[col][sym]; 
        }
        EXPECT_EQ(lottery.volatilit[col].size(), expectedSum);
    }
}

// Test that the startLottery method populates lotteryResultTab correctly
TEST_F(LotteryTest, StartLotteryPopulatesResults) {
    lottery.startLottery();

    for (int col = 0; col < Lottery::NR_COLUMN; ++col) {
        for (int row = 0; row < Lottery::NR_ROW; ++row) {
            int value = lottery.lotteryResultTab[col][row]; 
            EXPECT_GE(value, 0); // Ensure value is non-negative
            EXPECT_LT(value, Lottery::NR_SYMBOLS); // Ensure value is within the symbol range
        }
    }
}

// Test that scatter symbol is handled correctly in startLottery
TEST_F(LotteryTest, StartLotteryScatterHandledCorrectly) {
    lottery.startLottery();

    int scatterCount = 0;
    for (int col = 0; col < Lottery::NR_COLUMN; ++col) {
        for (int row = 0; row < Lottery::NR_ROW; ++row) {
            if (lottery.lotteryResultTab[col][row] == 0) {
                scatterCount++;
            }
        }
    }
    EXPECT_LE(scatterCount, 1); // Ensure scatter symbol (0) appears at most once
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}