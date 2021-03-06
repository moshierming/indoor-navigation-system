#ifndef INS_SERVER_TEST_MOCKS_DATA_STORE_HPP
#define INS_SERVER_TEST_MOCKS_DATA_STORE_HPP

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "data_store.hpp"

namespace ins_service
{

class MockDataStore;

extern ::testing::NiceMock<MockDataStore>* g_mocked_data_store_;

class MockDataStore : public DataStore
{
public:
    MOCK_METHOD1(Init, void(const std::string&));

    MOCK_METHOD0(Close, void());

    MOCK_METHOD2(UpdateDeviceLocation, bool(const std::string&, Position));

    MOCK_METHOD2(AssignDeviceToEmployee, bool(const std::string&, const std::string&));

    MOCK_METHOD2(InsertRSSIReadings, bool(const std::string&, std::vector<AccessPointRssiPair>));

    MOCK_METHOD3(GetPosition, bool(const std::string&, QueryT, Position&));

    MOCK_METHOD1(CreateDeviceTable, bool(const std::string&));

    MOCK_METHOD1(ClearDeviceTable, bool(const std::string&));

    MOCK_METHOD1(GetDistinctAccessPoints, std::vector<AccessPoint>(const std::string&));

    MOCK_METHOD2(GetRSSISeriesData, std::vector<int32_t>(const std::string&, AccessPoint));

    MOCK_METHOD2(GetRSSISeriesData, std::vector<AccessPointRssiListPair>(const std::string&, std::vector<AccessPoint>));

    ~MockDataStore()
    {
        g_mocked_data_store_ = nullptr;
    }
};
}

#endif // INS_SERVER_TEST_MOCKS_DATA_STORE_HPP
