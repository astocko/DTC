#ifndef _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 
#include <stddef.h>

#include "DTCProtocol.h"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

namespace DTC
{

	/****************************************************************************/
	// s_EncodingRequest

	/*============================================================================
	Will get the size of the message received over the network
	----------------------------------------------------------------------------*/
	uint16_t s_EncodingRequest::GetMessageSize()
	{
		return Size;
	}

	/*============================================================================
	Performs a safe copy of data into this structure instance from the given
	data pointer.
	----------------------------------------------------------------------------*/
	void s_EncodingRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_EncodingRequest), *static_cast<uint16_t*>( p_SourceData)  ));
	}

	/*==========================================================================*/
	int32_t s_EncodingRequest::GetProtocolVersion()
	{
		if (Size < offsetof(s_EncodingRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	EncodingEnum s_EncodingRequest::GetEncoding()
	{
		if (Size < offsetof(s_EncodingRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return (EncodingEnum)0;

		return Encoding;
	}

	/*==========================================================================*/
	const char* s_EncodingRequest::GetProtocolType()
	{
		if (Size < offsetof(s_EncodingRequest, ProtocolType) + sizeof(ProtocolType))
			return "";

		ProtocolType[sizeof(ProtocolType) - 1] = '\0';  // Ensure that the null terminator exists

		return ProtocolType;
	}

	/*==========================================================================*/
	void s_EncodingRequest::SetProtocolType(const char* NewValue)
	{
		//Do not use the secure version of this function. This version of the function will set the remaining bytes in the destination after the null terminator to nulls. The secure version does not do this.
		strncpy(ProtocolType, NewValue, sizeof(ProtocolType) - 1);
	}

	/****************************************************************************/
	// s_EncodingResponse

	/*============================================================================
	Will get the size of the message received over the network
	----------------------------------------------------------------------------*/
	uint16_t s_EncodingResponse::GetMessageSize()
	{
		return Size;
	}

	/*============================================================================
	Performs a safe copy of data into this structure instance from the given
	data pointer.
	----------------------------------------------------------------------------*/
	void s_EncodingResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_EncodingResponse), *static_cast<uint16_t*>( p_SourceData)  ));
	}

	/*==========================================================================*/
	int32_t s_EncodingResponse::GetProtocolVersion()
	{
		if (Size < offsetof(s_EncodingResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	EncodingEnum s_EncodingResponse::GetEncoding()
	{
		if (Size < offsetof(s_EncodingResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return (EncodingEnum)0;

		return Encoding;
	}

	/*==========================================================================*/
	const char* s_EncodingResponse::GetProtocolType()
	{
		if (Size < offsetof(s_EncodingResponse, ProtocolType) + sizeof(ProtocolType))
			return "";

		ProtocolType[sizeof(ProtocolType) - 1] = '\0';  // Ensure that the null terminator exists

		return ProtocolType;
	}

	/*==========================================================================*/
	void s_EncodingResponse::SetProtocolType(const char* NewValue)
	{
		strncpy(ProtocolType, NewValue, sizeof(ProtocolType) - 1);
	}

	/****************************************************************************/
	// s_LogonRequest

	/*============================================================================
	Will get the size of the message received over the network
	----------------------------------------------------------------------------*/
	uint16_t s_LogonRequest::GetMessageSize()
	{
		return Size;
	}

	/*============================================================================
	Performs a safe copy of data into this structure instance from the given
	data pointer.
	----------------------------------------------------------------------------*/
	void s_LogonRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_LogonRequest), *static_cast<uint16_t*>( p_SourceData)  ));
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetProtocolVersion()
	{
		if (Size < offsetof(s_LogonRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetUsername()
	{
		if (Size < offsetof(s_LogonRequest, Username) + sizeof(Username))
			return "";

		Username[sizeof(Username) - 1] = '\0';  // Ensure that the null terminator exists

		return Username;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetUsername(const char* NewValue)
	{

		strncpy(Username, NewValue, sizeof(Username) - 1);
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetPassword()
	{
		if (Size < offsetof(s_LogonRequest, Password) + sizeof(Password))
			return "";

		Password[sizeof(Password) - 1] = '\0';

		return Password;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetPassword(const char* NewValue)
	{
		strncpy(Password, NewValue, sizeof(Password) - 1);
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetGeneralTextData()
	{
		if (Size < offsetof(s_LogonRequest, GeneralTextData) + sizeof(GeneralTextData))
			return "";

		GeneralTextData[sizeof(GeneralTextData) - 1] = '\0';

		return GeneralTextData;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetGeneralTextData(const char* NewValue)
	{
		strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_1()
	{
		if (Size < offsetof(s_LogonRequest, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}
	
	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_2()
	{
		if (Size < offsetof(s_LogonRequest, Integer_2) + sizeof(Integer_2))
			return 0;

		return Integer_2;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetHeartbeatIntervalInSeconds()
	{
		if (Size < offsetof(s_LogonRequest, HeartbeatIntervalInSeconds) + sizeof(HeartbeatIntervalInSeconds))
			return 0;

		return HeartbeatIntervalInSeconds;
	}

	/*==========================================================================*/
	TradeModeEnum s_LogonRequest::GetTradeMode()
	{
		if (Size < offsetof(s_LogonRequest, TradeMode) + sizeof(TradeMode))
			return (TradeModeEnum)0;

		return TradeMode;
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetTradeAccount()
	{
		if (Size < offsetof(s_LogonRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetHardwareIdentifier()
	{
		if (Size < offsetof(s_LogonRequest, HardwareIdentifier) + sizeof(HardwareIdentifier))
			return "";

		HardwareIdentifier[sizeof(HardwareIdentifier) - 1] = '\0';

		return HardwareIdentifier;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetHardwareIdentifier(const char* NewValue)
	{
		strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetClientName()
	{
		if (Size < offsetof(s_LogonRequest, ClientName) + sizeof(ClientName))
			return "";

		ClientName[sizeof(ClientName) - 1] = '\0';

		return ClientName;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetClientName(const char* NewValue)
	{
		strncpy(ClientName, NewValue, sizeof(ClientName) - 1);
	}

	/****************************************************************************/
	// s_LogonResponse

	/*==========================================================================*/
	uint16_t s_LogonResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_LogonResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_LogonResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_LogonResponse::GetProtocolVersion() const
	{
		if (Size < offsetof(s_LogonResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	LogonStatusEnum s_LogonResponse::GetResult() const
	{
		if (Size < offsetof(s_LogonResponse, Result) + sizeof(Result))
			return (LogonStatusEnum)0;

		return Result;
	}
	
	/*==========================================================================*/
	const char* s_LogonResponse::GetResultText()
	{
		if (Size < offsetof(s_LogonResponse, ResultText) + sizeof(ResultText))
			return "";

		ResultText[sizeof(ResultText) - 1] = '\0';

		return ResultText;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetResultText(const char* NewValue)
	{
		strncpy(ResultText, NewValue, sizeof(ResultText) - 1);
	}

	/*==========================================================================*/
	const char* s_LogonResponse::GetReconnectAddress()
	{
		if (Size < offsetof(s_LogonResponse, ReconnectAddress) + sizeof(ReconnectAddress))
			return "";

		ReconnectAddress[sizeof(ReconnectAddress) - 1] = '\0';

		return ReconnectAddress;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetReconnectAddress(const char* NewValue)
	{
		strncpy(ReconnectAddress, NewValue, sizeof(ReconnectAddress) - 1);
	}

	/*==========================================================================*/
	int32_t s_LogonResponse::GetInteger_1() const
	{
		if (Size < offsetof(s_LogonResponse, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}


	/*==========================================================================*/
	const char* s_LogonResponse::GetServerName()
	{
		if (Size < offsetof(s_LogonResponse, ServerName) + sizeof(ServerName))
			return "";

		ServerName[sizeof(ServerName) - 1] = '\0';

		return ServerName;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetServerName(const char* NewValue)
	{
		strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk() const
	{
		if (Size < offsetof(s_LogonResponse, MarketDepthUpdatesBestBidAndAsk) + sizeof(MarketDepthUpdatesBestBidAndAsk))
			return 0;

		return MarketDepthUpdatesBestBidAndAsk;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetTradingIsSupported() const
	{
		if (Size < offsetof(s_LogonResponse, TradingIsSupported) + sizeof(TradingIsSupported))
			return 0;

		return TradingIsSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOCOOrdersSupported() const
	{
		if (Size < offsetof(s_LogonResponse, OCOOrdersSupported) + sizeof(OCOOrdersSupported))
			return 0;

		return OCOOrdersSupported;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOrderCancelReplaceSupported() const
	{
		if (Size < offsetof(s_LogonResponse, OrderCancelReplaceSupported) + sizeof(OrderCancelReplaceSupported))
			return 0;

		return OrderCancelReplaceSupported;
	}


	/*==========================================================================*/
	const char* s_LogonResponse::GetSymbolExchangeDelimiter()
	{
		if (Size < offsetof(s_LogonResponse, SymbolExchangeDelimiter) + sizeof(SymbolExchangeDelimiter))
			return "";

		SymbolExchangeDelimiter[sizeof(SymbolExchangeDelimiter) - 1] = '\0';

		return SymbolExchangeDelimiter;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetSymbolExchangeDelimiter(const char* NewValue)
	{
		strncpy(SymbolExchangeDelimiter, NewValue, sizeof(SymbolExchangeDelimiter) - 1);
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetSecurityDefinitionsSupported() const
	{
		if (Size < offsetof(s_LogonResponse, SecurityDefinitionsSupported) + sizeof(SecurityDefinitionsSupported))
			return 0;

		return SecurityDefinitionsSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetHistoricalPriceDataSupported() const
	{
		if (Size < offsetof(s_LogonResponse, HistoricalPriceDataSupported) + sizeof(HistoricalPriceDataSupported))
			return 0;

		return HistoricalPriceDataSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetResubscribeWhenMarketDataFeedAvailable() const
	{
		if (Size < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedAvailable) + sizeof(ResubscribeWhenMarketDataFeedAvailable))
			return 0;

		return ResubscribeWhenMarketDataFeedAvailable;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDepthIsSupported() const
	{
		if (Size < offsetof(s_LogonResponse, MarketDepthIsSupported) + sizeof(MarketDepthIsSupported))
			return 0;

		return MarketDepthIsSupported;
	}
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOneHistoricalPriceDataRequestPerConnection() const
	{
		if (Size < offsetof(s_LogonResponse, OneHistoricalPriceDataRequestPerConnection) + sizeof(OneHistoricalPriceDataRequestPerConnection))
			return 0;

		return OneHistoricalPriceDataRequestPerConnection;
	}
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetUseIntegerPriceOrderMessages() const
	{
		if (Size < offsetof(s_LogonResponse, UseIntegerPriceOrderMessages) + sizeof(UseIntegerPriceOrderMessages))
			return 0;

		return UseIntegerPriceOrderMessages;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetBracketOrdersSupported() const
	{
		if (Size < offsetof(s_LogonResponse, BracketOrdersSupported) + sizeof(BracketOrdersSupported))
			return 0;

		return BracketOrdersSupported;
	}
	
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetUsesMultiplePositionsPerSymbolAndTradeAccount() const
	{
		if (Size < offsetof(s_LogonResponse, UsesMultiplePositionsPerSymbolAndTradeAccount) + sizeof(UsesMultiplePositionsPerSymbolAndTradeAccount))
			return 0;

		return UsesMultiplePositionsPerSymbolAndTradeAccount;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDataSupported() const
	{
		if (Size < offsetof(s_LogonResponse, MarketDataSupported) + sizeof(MarketDataSupported))
			return 0;

		return MarketDataSupported;
	}

	/****************************************************************************/
	// s_LogoffRequest

	/*==========================================================================*/
	uint16_t s_Logoff::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_Logoff::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_Logoff), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	const char* s_Logoff::GetReason()
	{
		if (Size < offsetof(s_Logoff, Reason) + sizeof(Reason))
			return "";

		Reason[sizeof(Reason) - 1] = '\0';

		return Reason;
	}
	/*==========================================================================*/
	void s_Logoff::SetReason(const char* NewValue)
	{
		strncpy(Reason, NewValue, sizeof(Reason) - 1);
	}
	/*==========================================================================*/
	uint8_t s_Logoff::GetDoNotReconnect()
	{
		if (Size < offsetof(s_Logoff, DoNotReconnect) + sizeof(DoNotReconnect))
			return false;

		return DoNotReconnect;
	}


	/****************************************************************************/
	// s_Heartbeat

	/*==========================================================================*/
	uint16_t s_Heartbeat::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_Heartbeat::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_Heartbeat), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint32_t s_Heartbeat::GetNumDroppedMessages()
	{
		if (Size < offsetof(s_Heartbeat, NumDroppedMessages) + sizeof(NumDroppedMessages))
			return 0;

		return NumDroppedMessages;
	}


	/*==========================================================================*/
	t_DateTime s_Heartbeat::GetCurrentDateTime()
	{
		if (Size < offsetof(s_Heartbeat, CurrentDateTime) + sizeof(CurrentDateTime))
			return 0;

		return CurrentDateTime;
	}


	/****************************************************************************/
	// s_MarketDataFeedStatus

	/*==========================================================================*/
	uint16_t s_MarketDataFeedStatus::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataFeedStatus::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedStatus), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	MarketDataFeedStatusEnum s_MarketDataFeedStatus::GetStatus()
	{
		if (Size < offsetof(s_MarketDataFeedStatus, Status) + sizeof(Status))
			return (MarketDataFeedStatusEnum)0;

		return Status;
	}


	/****************************************************************************/
	// s_MarketDataFeedSymbolStatus

	/*==========================================================================*/
	uint16_t s_MarketDataFeedSymbolStatus::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataFeedSymbolStatus::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedSymbolStatus), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataFeedSymbolStatus::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataFeedSymbolStatus, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/*==========================================================================*/
	MarketDataFeedStatusEnum s_MarketDataFeedSymbolStatus::GetStatus()
	{
		if (Size < offsetof(s_MarketDataFeedSymbolStatus, Status) + sizeof(Status))
			return (MarketDataFeedStatusEnum)0;

		return Status;
	}


	/****************************************************************************/
	// s_MarketDataRequest

	/*==========================================================================*/
	uint16_t s_MarketDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	RequestActionEnum s_MarketDataRequest::GetRequestAction()
	{
		if (Size < offsetof(s_MarketDataRequest, RequestAction) + sizeof(RequestAction))
			return (RequestActionEnum)0;

		return RequestAction;
	}


	/*==========================================================================*/
	uint16_t s_MarketDataRequest::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/*==========================================================================*/
	const char* s_MarketDataRequest::GetSymbol()
	{
		if (Size < offsetof(s_MarketDataRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_MarketDataRequest::GetExchange()
	{
		if (Size < offsetof(s_MarketDataRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/****************************************************************************/
	// s_MarketDepthRequest

	/*==========================================================================*/
	uint16_t s_MarketDepthRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	RequestActionEnum s_MarketDepthRequest::GetRequestAction()
	{
		if (Size < offsetof(s_MarketDepthRequest, RequestAction) + sizeof(RequestAction))
			return (RequestActionEnum)0;

		return RequestAction;
	}


	/*==========================================================================*/
	uint16_t s_MarketDepthRequest::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/*==========================================================================*/
	const char* s_MarketDepthRequest::GetSymbol()
	{
		if (Size < offsetof(s_MarketDepthRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_MarketDepthRequest::GetExchange()
	{
		if (Size < offsetof(s_MarketDepthRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	int32_t s_MarketDepthRequest::GetNumLevels()
	{
		if (Size < offsetof(s_MarketDepthRequest, NumLevels) + sizeof(NumLevels))
			return 0;

		return NumLevels;
	}


	/****************************************************************************/
	// s_MarketDataReject

	/*==========================================================================*/
	uint16_t s_MarketDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataReject), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataReject::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataReject, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	const char* s_MarketDataReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDataReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	void s_MarketDataReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/****************************************************************************/
	// s_MarketDepthReject

	/*==========================================================================*/
	uint16_t s_MarketDepthReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthReject), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthReject::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthReject, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	const char* s_MarketDepthReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDepthReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	void s_MarketDepthReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/****************************************************************************/
	// s_MarketDataSnapshot

	/*==========================================================================*/
	uint16_t s_MarketDataSnapshot::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataSnapshot::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataSnapshot), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataSnapshot::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSessionSettlementPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionSettlementPrice) + sizeof(SessionSettlementPrice))
			return 0;

		return SessionSettlementPrice;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSessionOpenPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionOpenPrice) + sizeof(SessionOpenPrice))
			return 0;

		return SessionOpenPrice;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSessionHighPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionHighPrice) + sizeof(SessionHighPrice))
			return 0;

		return SessionHighPrice;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSessionLowPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionLowPrice) + sizeof(SessionLowPrice))
			return 0;

		return SessionLowPrice;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSessionVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionVolume) + sizeof(SessionVolume))
			return 0;

		return SessionVolume;
	}


	/*==========================================================================*/
	uint32_t s_MarketDataSnapshot::GetSessionNumTrades()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionNumTrades) + sizeof(SessionNumTrades))
			return 0;

		return SessionNumTrades;
	}

	/*==========================================================================*/
	uint32_t s_MarketDataSnapshot::GetOpenInterest()
	{
		if (Size < offsetof(s_MarketDataSnapshot, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetBidPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, BidPrice) + sizeof(BidPrice))
			return 0;

		return BidPrice;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetAskPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, AskPrice) + sizeof(AskPrice))
			return 0;

		return AskPrice;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetAskQuantity()
	{
		if (Size < offsetof(s_MarketDataSnapshot, AskQuantity) + sizeof(AskQuantity))
			return 0;

		return AskQuantity;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetBidQuantity()
	{
		if (Size < offsetof(s_MarketDataSnapshot, BidQuantity) + sizeof(BidQuantity))
			return 0;

		return BidQuantity;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetLastTradePrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradePrice) + sizeof(LastTradePrice))
			return 0;

		return LastTradePrice;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetLastTradeVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradeVolume) + sizeof(LastTradeVolume))
			return 0;

		return LastTradeVolume;
	}
	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataSnapshot::GetLastTradeDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradeDateTime) + sizeof(LastTradeDateTime))
			return 0;

		return LastTradeDateTime;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataSnapshot::GetBidAskDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot, BidAskDateTime) + sizeof(BidAskDateTime))
			return 0;

		return BidAskDateTime;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataSnapshot::GetSessionSettlementDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SessionSettlementDateTime) + sizeof(SessionSettlementDateTime))
			return 0;

		return SessionSettlementDateTime;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataSnapshot::GetTradingSessionDate()
	{
		if (Size < offsetof(s_MarketDataSnapshot, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}


	/****************************************************************************/
	// s_MarketDataSnapshot_Int

	/*==========================================================================*/
	uint16_t s_MarketDataSnapshot_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataSnapshot_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataSnapshot_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataSnapshot_Int::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetSessionSettlementPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionSettlementPrice) + sizeof(SessionSettlementPrice))
			return 0;

		return SessionSettlementPrice;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetSessionOpenPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionOpenPrice) + sizeof(SessionOpenPrice))
			return 0;

		return SessionOpenPrice;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetSessionHighPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionHighPrice) + sizeof(SessionHighPrice))
			return 0;

		return SessionHighPrice;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetSessionLowPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionLowPrice) + sizeof(SessionLowPrice))
			return 0;

		return SessionLowPrice;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetSessionVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionVolume) + sizeof(SessionVolume))
			return 0;

		return SessionVolume;
	}


	/*==========================================================================*/
	uint32_t s_MarketDataSnapshot_Int::GetSessionNumTrades()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionNumTrades) + sizeof(SessionNumTrades))
			return 0;

		return SessionNumTrades;
	}

	/*==========================================================================*/
	uint32_t s_MarketDataSnapshot_Int::GetOpenInterest()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}

	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetBidPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, BidPrice) + sizeof(BidPrice))
			return 0;

		return BidPrice;
	}
	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetAskPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, AskPrice) + sizeof(AskPrice))
			return 0;

		return AskPrice;
	}

	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetAskQuantity()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, AskQuantity) + sizeof(AskQuantity))
			return 0;

		return AskQuantity;
	}


	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetBidQuantity()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, BidQuantity) + sizeof(BidQuantity))
			return 0;

		return BidQuantity;
	}

	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetLastTradePrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradePrice) + sizeof(LastTradePrice))
			return 0;

		return LastTradePrice;
	}

	/*==========================================================================*/
	int32_t s_MarketDataSnapshot_Int::GetLastTradeVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradeVolume) + sizeof(LastTradeVolume))
			return 0;

		return LastTradeVolume;
	}
	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataSnapshot_Int::GetLastTradeDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradeDateTime) + sizeof(LastTradeDateTime))
			return 0;

		return LastTradeDateTime;
	}
	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataSnapshot_Int::GetBidAskDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, BidAskDateTime) + sizeof(BidAskDateTime))
			return 0;

		return BidAskDateTime;
	}
	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataSnapshot_Int::GetSessionSettlementDateTime()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SessionSettlementDateTime) + sizeof(SessionSettlementDateTime))
			return 0;

		return SessionSettlementDateTime;
	}
	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataSnapshot_Int::GetTradingSessionDate()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}


	/****************************************************************************/
	// s_MarketDepthFullUpdate20

	/*==========================================================================*/
	uint16_t s_MarketDepthFullUpdate20::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthFullUpdate20::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthFullUpdate20), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthFullUpdate20::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthFullUpdate20, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/****************************************************************************/
	// s_MarketDepthFullUpdate10

	/*==========================================================================*/
	uint16_t s_MarketDepthFullUpdate10::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthFullUpdate10::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthFullUpdate10), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthFullUpdate10::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthFullUpdate10, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/****************************************************************************/
	// s_MarketDepthSnapshotLevel

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDepthSnapshotLevel::GetSide()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	double s_MarketDepthSnapshotLevel::GetPrice()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthSnapshotLevel::GetQuantity()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Quantity) + sizeof(Quantity))
			return 0.0;

		return Quantity;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel::GetLevel()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Level) + sizeof(Level))
			return 0;

		return Level;
	}

	/*==========================================================================*/
	uint8_t s_MarketDepthSnapshotLevel::GetIsFirstMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, IsFirstMessageInBatch) + sizeof(IsFirstMessageInBatch))
			return 0;

		return IsFirstMessageInBatch;
	}

	/*==========================================================================*/
	uint8_t s_MarketDepthSnapshotLevel::GetIsLastMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, IsLastMessageInBatch) + sizeof(IsLastMessageInBatch))
			return 0;

		return IsLastMessageInBatch;
	}

	/*==========================================================================*/
	void s_MarketDepthSnapshotLevel::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthSnapshotLevel), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/****************************************************************************/
	// s_MarketDepthSnapshotLevel_Int

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel_Int::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDepthSnapshotLevel_Int::GetSide()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	int32_t s_MarketDepthSnapshotLevel_Int::GetPrice()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	int32_t s_MarketDepthSnapshotLevel_Int::GetQuantity()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthSnapshotLevel_Int::GetLevel()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Level) + sizeof(Level))
			return 0;

		return Level;
	}

	/*==========================================================================*/
	uint8_t s_MarketDepthSnapshotLevel_Int::GetIsFirstMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, IsFirstMessageInBatch) + sizeof(IsFirstMessageInBatch))
			return 0;

		return IsFirstMessageInBatch;
	}

	/*==========================================================================*/
	uint8_t s_MarketDepthSnapshotLevel_Int::GetIsLastMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, IsLastMessageInBatch) + sizeof(IsLastMessageInBatch))
			return 0;

		return IsLastMessageInBatch;
	}

	/*==========================================================================*/
	void s_MarketDepthSnapshotLevel_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthSnapshotLevel_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}


	/****************************************************************************/
	// s_MarketDepthIncrementalUpdate

	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevel::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthUpdateLevel::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthUpdateLevel), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevel::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDepthUpdateLevel::GetSide()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}
	/*==========================================================================*/
	double s_MarketDepthUpdateLevel::GetPrice() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthUpdateLevel::GetQuantity() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	MarketDepthUpdateTypeEnum s_MarketDepthUpdateLevel::GetUpdateType() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDepthUpdateLevel::GetDateTime()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel, DateTime) + sizeof(DateTime))
			return 0.0;

		return DateTime;
	}



	/****************************************************************************/
	// s_MarketDepthIncrementalUpdate_Int

	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevel_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthUpdateLevel_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthUpdateLevel_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevel_Int::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDepthUpdateLevel_Int::GetSide()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}


	/*==========================================================================*/
	int32_t s_MarketDepthUpdateLevel_Int::GetPrice() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	int32_t s_MarketDepthUpdateLevel_Int::GetQuantity() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	MarketDepthUpdateTypeEnum s_MarketDepthUpdateLevel_Int::GetUpdateType() 
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDepthUpdateLevel_Int::GetDateTime()
	{
		if (Size < offsetof(s_MarketDepthUpdateLevel_Int, DateTime) + sizeof(DateTime))
			return 0.0;

		return DateTime;
	}


	/****************************************************************************/
	// s_MarketDepthIncrementalUpdateCompact

	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevelCompact::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthUpdateLevelCompact::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthUpdateLevelCompact), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthUpdateLevelCompact::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDepthUpdateLevelCompact::GetSide() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	float s_MarketDepthUpdateLevelCompact::GetPrice() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, Price) + sizeof(Price))
			return 0.0f;

		return Price;
	}

	/*==========================================================================*/
	float s_MarketDepthUpdateLevelCompact::GetQuantity() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	MarketDepthUpdateTypeEnum s_MarketDepthUpdateLevelCompact::GetUpdateType() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDepthUpdateLevelCompact::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDepthUpdateLevelCompact, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/****************************************************************************/
	// s_SettlementIncrementalUpdate

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionSettlement::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionSettlement::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionSettlement), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionSettlement::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateSessionSettlement::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionSettlement::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

		/****************************************************************************/
	// s_SettlementIncrementalUpdate_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionSettlement_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionSettlement_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionSettlement_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionSettlement_Int::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateSessionSettlement_Int::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionSettlement_Int::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionSettlement_Int, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionOpen

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionOpen::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionOpen::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionOpen), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionOpen::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateSessionOpen::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionOpen::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionOpen_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionOpen_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionOpen_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionOpen_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionOpen_Int::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateSessionOpen_Int::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionOpen_Int::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionOpen_Int, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionNumTrades

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionNumTrades::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionNumTrades::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionNumTrades), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionNumTrades::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionNumTrades, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateSessionNumTrades::GetNumTrades() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionNumTrades, NumTrades) + sizeof(NumTrades))
			return 0;

		return NumTrades;
	}


	/****************************************************************************/
	// s_MarketDataUpdateTradingSessionDate

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTradingSessionDate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateTradingSessionDate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateTradingSessionDate), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTradingSessionDate::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradingSessionDate, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateTradingSessionDate::GetDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradingSessionDate, Date) + sizeof(Date))
			return 0;

		return Date;
	}


	/****************************************************************************/
	// s_TradeIncrementalUpdate

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTrade::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateTrade::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateTrade), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTrade::GetSymbolID() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}
	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDataUpdateTrade::GetAtBidOrAsk() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade, AtBidOrAsk) + sizeof(AtBidOrAsk))
			return BID_ASK_UNSET;

		return AtBidOrAsk;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateTrade::GetPrice() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateTrade::GetVolume() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/

	t_DateTimeWithMilliseconds s_MarketDataUpdateTrade::GetDateTime() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}


		/****************************************************************************/
	// s_TradeIncrementalUpdate_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTrade_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateTrade_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateTrade_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTrade_Int::GetSymbolID() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}
	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDataUpdateTrade_Int::GetAtBidOrAsk() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade_Int, AtBidOrAsk) + sizeof(AtBidOrAsk))
			return BID_ASK_UNSET;

		return AtBidOrAsk;
	}
	/*==========================================================================*/
	int32_t s_MarketDataUpdateTrade_Int::GetPrice() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}
	/*==========================================================================*/
	int32_t s_MarketDataUpdateTrade_Int::GetVolume() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade_Int, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataUpdateTrade_Int::GetDateTime() 
	{
		if (Size < offsetof(s_MarketDataUpdateTrade_Int, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/****************************************************************************/
	// s_QuoteIncrementalUpdate

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateBidAsk::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateBidAsk::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateBidAsk), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateBidAsk::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateBidAsk::GetBidPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, BidPrice) + sizeof(BidPrice))
			return 0.0;

		return BidPrice;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAsk::GetBidQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, BidQuantity) + sizeof(BidQuantity))
			return 0;

		return BidQuantity;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateBidAsk::GetAskPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, AskPrice) + sizeof(AskPrice))
			return 0.0;

		return AskPrice;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAsk::GetAskQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, AskQuantity) + sizeof(AskQuantity))
			return 0;

		return AskQuantity;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateBidAsk::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/****************************************************************************/
	// s_QuoteIncrementalUpdate_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateBidAsk_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateBidAsk_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateBidAsk_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateBidAsk_Int::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateBidAsk_Int::GetBidPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, BidPrice) + sizeof(BidPrice))
			return 0;

		return BidPrice;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateBidAsk_Int::GetBidQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, BidQuantity) + sizeof(BidQuantity))
			return 0;

		return BidQuantity;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateBidAsk_Int::GetAskPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, AskPrice) + sizeof(AskPrice))
			return 0;

		return AskPrice;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateBidAsk_Int::GetAskQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, AskQuantity) + sizeof(AskQuantity))
			return 0;

		return AskQuantity;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateBidAsk_Int::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAsk_Int, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}


	/****************************************************************************/
	// s_MarketDataUpdateBidAskCompact

	/*==========================================================================*/

	uint16_t s_MarketDataUpdateBidAskCompact::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateBidAskCompact::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateBidAskCompact), *static_cast<uint16_t*>(p_SourceData) ));
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAskCompact::GetBidPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, BidPrice) + sizeof(BidPrice))
			return 0;

		return BidPrice;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAskCompact::GetBidQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, BidQuantity) + sizeof(BidQuantity))
			return 0;

		return BidQuantity;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAskCompact::GetAskPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, AskPrice) + sizeof(AskPrice))
			return  0;

		return AskPrice;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateBidAskCompact::GetAskQuantity() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, AskQuantity) + sizeof(AskQuantity))
			return 0;

		return AskQuantity;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateBidAskCompact::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateBidAskCompact::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateBidAskCompact, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/****************************************************************************/
	// s_TradeIncrementalUpdateCompact

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTradeCompact::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateTradeCompact::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateTradeCompact), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	float s_MarketDataUpdateTradeCompact::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradeCompact, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	float s_MarketDataUpdateTradeCompact::GetVolume() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradeCompact, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateTradeCompact::GetDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradeCompact, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateTradeCompact::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradeCompact, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_MarketDataUpdateTradeCompact::GetAtBidOrAsk() const
	{
		if (Size < offsetof(s_MarketDataUpdateTradeCompact, AtBidOrAsk) + sizeof(AtBidOrAsk))
			return BID_ASK_UNSET;

		return AtBidOrAsk;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionVolume

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionVolume::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionVolume::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionVolume), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionVolume::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionVolume, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateSessionVolume::GetVolume() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionVolume, Volume) + sizeof(Volume))
			return 0.0;

		return Volume;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionVolume::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionVolume, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}


	/****************************************************************************/
	// s_OpenInterestIncrementalUpdate

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateOpenInterest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateOpenInterest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateOpenInterest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateOpenInterest::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionVolume, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	uint32_t s_MarketDataUpdateOpenInterest::GetOpenInterest() const
	{
		if (Size < offsetof(s_MarketDataUpdateOpenInterest, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionHigh

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionHigh::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionHigh::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionHigh), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionHigh::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateSessionHigh::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionHigh::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionHigh_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionHigh_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionHigh_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionHigh_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionHigh_Int::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateSessionHigh_Int::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionHigh_Int::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionHigh_Int, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionLow

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionLow::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionLow::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionLow), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionLow::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateSessionLow::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionLow::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateSessionLow_Int

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionLow_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateSessionLow_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateSessionLow_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateSessionLow_Int::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow_Int, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDataUpdateSessionLow_Int::GetPrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_MarketDataUpdateSessionLow_Int::GetTradingSessionDate() const
	{
		if (Size < offsetof(s_MarketDataUpdateSessionLow_Int, TradingSessionDate) + sizeof(TradingSessionDate))
			return 0;

		return TradingSessionDate;
	}

	/****************************************************************************/
	// s_MarketDataUpdateLastTradeSnapshot

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateLastTradeSnapshot::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataUpdateLastTradeSnapshot::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateLastTradeSnapshot), *static_cast<uint16_t*>(p_SourceData)));
	}

	/*==========================================================================*/
	uint16_t s_MarketDataUpdateLastTradeSnapshot::GetSymbolID() const
	{
		if (Size < offsetof(s_MarketDataUpdateLastTradeSnapshot, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateLastTradeSnapshot::GetLastTradePrice() const
	{
		if (Size < offsetof(s_MarketDataUpdateLastTradeSnapshot, LastTradePrice) + sizeof(LastTradePrice))
			return 0.0;

		return LastTradePrice;
	}

	/*==========================================================================*/
	double s_MarketDataUpdateLastTradeSnapshot::GetLastTradeVolume() const
	{
		if (Size < offsetof(s_MarketDataUpdateLastTradeSnapshot, LastTradeVolume) + sizeof(LastTradeVolume))
			return 0.0;

		return LastTradeVolume;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_MarketDataUpdateLastTradeSnapshot::GetLastTradeDateTime() const
	{
		if (Size < offsetof(s_MarketDataUpdateLastTradeSnapshot, LastTradeDateTime) + sizeof(LastTradeDateTime))
			return 0.0;

		return LastTradeDateTime;
	}

	/****************************************************************************/
	// s_SubmitNewSingleOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewSingleOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewSingleOrder), *static_cast<uint16_t*>( p_SourceData) ));
	}
	
	/*==========================================================================*/
	const char* s_SubmitNewSingleOrder::GetSymbol()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}
	/*==========================================================================*/
	const char* s_SubmitNewSingleOrder::GetExchange()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}	
	/*==========================================================================*/
	const char* s_SubmitNewSingleOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}	

	/*==========================================================================*/
	const char* s_SubmitNewSingleOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewSingleOrder::GetOrderType()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, OrderType) + sizeof(OrderType))
			return ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	BuySellEnum s_SubmitNewSingleOrder::GetBuySell()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, BuySell) + sizeof(BuySell))
			return BUY_SELL_UNSET;

		return BuySell;	
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice1()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price1) + sizeof(Price1))
			return 0.0;

		return Price1;
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice2()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price2) + sizeof(Price2))
			return 0.0;

		return Price2;
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetQuantity()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Quantity) + sizeof(Quantity))
			return 0.0;

		return Quantity;
	}

	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewSingleOrder::GetTimeInForce()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, TimeInForce) + sizeof(TimeInForce))
			return TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	t_DateTime s_SubmitNewSingleOrder::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrder::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrder::GetIsParentOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}

	/*==========================================================================*/
	const char* s_SubmitNewSingleOrder::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;

	}

	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}

	/*==========================================================================*/
	OpenCloseTradeEnum s_SubmitNewSingleOrder::GetOpenOrClose()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, OpenOrClose) + sizeof(OpenOrClose))
			return TRADE_UNSET;

		return OpenOrClose;
	}


	/****************************************************************************/
	// s_SubmitNewSingleOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewSingleOrderInt), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_SubmitNewSingleOrderInt::GetSymbol()
	{
		if (Size < offsetof( s_SubmitNewSingleOrderInt, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}
	/*==========================================================================*/
	const char* s_SubmitNewSingleOrderInt::GetExchange()
	{
		if (Size < offsetof( s_SubmitNewSingleOrderInt, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}	
	/*==========================================================================*/
	const char* s_SubmitNewSingleOrderInt::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewSingleOrderInt, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}	

	/*==========================================================================*/
	const char* s_SubmitNewSingleOrderInt::GetClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewSingleOrderInt, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewSingleOrderInt::GetOrderType()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, OrderType) + sizeof(OrderType))
			return ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	BuySellEnum s_SubmitNewSingleOrderInt::GetBuySell()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, BuySell) + sizeof(BuySell))
			return BUY_SELL_UNSET;

		return BuySell;	
	}
	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetPrice1()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetPrice2()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}

	/*==========================================================================*/
	float s_SubmitNewSingleOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetQuantity()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewSingleOrderInt::GetTimeInForce()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, TimeInForce) + sizeof(TimeInForce))
			return TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	t_DateTime s_SubmitNewSingleOrderInt::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrderInt::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrderInt::GetIsParentOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}

	/*==========================================================================*/
	const char* s_SubmitNewSingleOrderInt::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewSingleOrderInt, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;

	}

	/*==========================================================================*/
	void s_SubmitNewSingleOrderInt::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}

	/*==========================================================================*/
	OpenCloseTradeEnum s_SubmitNewSingleOrderInt::GetOpenOrClose()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, OpenOrClose) + sizeof(OpenOrClose))
			return TRADE_UNSET;

		return OpenOrClose;
	}

	/****************************************************************************/
	// s_CancelReplaceOrder

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CancelReplaceOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CancelReplaceOrder), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	const char* s_CancelReplaceOrder::GetServerOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrder, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrder::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	const char* s_CancelReplaceOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice1()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price1) + sizeof(Price1))
			return 0.0;

		return Price1;
	}
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice2()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price2) + sizeof(Price2))
			return 0.0;

		return Price2;
	}
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetQuantity()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Quantity) + sizeof(Quantity))
			return 0.0;

		return Quantity;
	}
	/*==========================================================================*/
	uint8_t s_CancelReplaceOrder::GetPrice1IsSet()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price1IsSet) + sizeof(Price1IsSet))
			return 1;

		return Price1IsSet;
	}
	/*==========================================================================*/
	uint8_t s_CancelReplaceOrder::GetPrice2IsSet()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price2IsSet) + sizeof(Price2IsSet))
			return 1;

		return Price2IsSet;
	}
	/*==========================================================================*/
	OrderTypeEnum s_CancelReplaceOrder::GetOrderType()
	{
		if (Size < offsetof(s_CancelReplaceOrder, OrderType) + sizeof(OrderType))
			return ORDER_TYPE_UNSET;

		return OrderType;
	}
	/*==========================================================================*/
	TimeInForceEnum s_CancelReplaceOrder::GetTimeInForce()
	{
		if (Size < offsetof(s_CancelReplaceOrder, TimeInForce) + sizeof(TimeInForce))
			return TIF_UNSET;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_CancelReplaceOrder::GetGoodTillDateTime()
	{
		if (Size < offsetof(s_CancelReplaceOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/****************************************************************************/
	// s_CancelReplaceOrderInt

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CancelReplaceOrderInt::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CancelReplaceOrderInt), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	const char* s_CancelReplaceOrderInt::GetServerOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrderInt, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrderInt::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	const char* s_CancelReplaceOrderInt::GetClientOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrderInt, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrderInt::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetPrice1()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}
	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetPrice2()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}
	/*==========================================================================*/
	float s_CancelReplaceOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Divisor) + sizeof(Divisor))
			return 1.0f;

		return Divisor;
	}
	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetQuantity()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}
	/*==========================================================================*/
	uint8_t s_CancelReplaceOrderInt::GetPrice1IsSet()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price1IsSet) + sizeof(Price1IsSet))
			return 1;

		return Price1IsSet;
	}
	/*==========================================================================*/
	uint8_t s_CancelReplaceOrderInt::GetPrice2IsSet()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price2IsSet) + sizeof(Price2IsSet))
			return 1;

		return Price2IsSet;
	}
	/*==========================================================================*/
	OrderTypeEnum s_CancelReplaceOrderInt::GetOrderType()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, OrderType) + sizeof(OrderType))
			return ORDER_TYPE_UNSET;

		return OrderType;
	}
	/*==========================================================================*/
	TimeInForceEnum s_CancelReplaceOrderInt::GetTimeInForce()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, TimeInForce) + sizeof(TimeInForce))
			return TIF_UNSET;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_CancelReplaceOrderInt::GetGoodTillDateTime()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}



	/****************************************************************************/
	// s_CancelOrder

	/*==========================================================================*/
	uint16_t s_CancelOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CancelOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CancelOrder), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	const char* s_CancelOrder::GetServerOrderID()
	{
		if (Size < offsetof( s_CancelOrder, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_CancelOrder::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	const char* s_CancelOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_CancelOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_CancelOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewOCOOrder), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetClientOrderID_1(const char* NewValue)
	{
		strncpy(ClientOrderID_1, NewValue, sizeof(ClientOrderID_1) - 1);
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetClientOrderID_2(const char* NewValue)
	{
		strncpy(ClientOrderID_2, NewValue, sizeof(ClientOrderID_2) - 1);
	}

	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetClientOrderID_1()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ClientOrderID_1) + sizeof(ClientOrderID_1))
			return "";

		ClientOrderID_1[sizeof(ClientOrderID_1) - 1] = '\0';

		return ClientOrderID_1;
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetClientOrderID_2()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ClientOrderID_2) + sizeof(ClientOrderID_2))
			return "";

		ClientOrderID_2[sizeof(ClientOrderID_2) - 1] = '\0';

		return ClientOrderID_2;
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetSymbol()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetExchange()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_1()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_1) + sizeof(OrderType_1))
			return ORDER_TYPE_UNSET;

		return OrderType_1;	
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_2()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_2) + sizeof(OrderType_2))
			return ORDER_TYPE_UNSET;

		return OrderType_2;	
	}
	/*==========================================================================*/			 
	BuySellEnum s_SubmitNewOCOOrder::GetBuySell_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_1) + sizeof(BuySell_1))
			return (BuySellEnum)0;

		return BuySell_1;
	}
	/*==========================================================================*/
	BuySellEnum s_SubmitNewOCOOrder::GetBuySell_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_2) + sizeof(BuySell_2))
			return (BuySellEnum)0;

		return BuySell_2;
	}
	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewOCOOrder::GetTimeInForce()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, TimeInForce) + sizeof(TimeInForce))
			return (TimeInForceEnum)0;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_SubmitNewOCOOrder::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}	
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetParentTriggerClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ParentTriggerClientOrderID) + sizeof(ParentTriggerClientOrderID))
			return "";

		ParentTriggerClientOrderID[sizeof(ParentTriggerClientOrderID) - 1] = '\0';

		return ParentTriggerClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetParentTriggerClientOrderID(const char* NewValue)
	{
		strncpy(ParentTriggerClientOrderID, NewValue, sizeof(ParentTriggerClientOrderID) - 1);
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewOCOOrder::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_1) + sizeof(Price1_1))
			return 0.0;

		return Price1_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_1) + sizeof(Price2_1))
			return 0.0;

		return Price2_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_2) + sizeof(Price1_2))
			return 0.0;

		return Price1_2;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_2) + sizeof(Price2_2))
			return 0.0;

		return Price2_2;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetQuantity_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Quantity_1) + sizeof(Quantity_1))
			return 0.0;

		return Quantity_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetQuantity_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Quantity_2) + sizeof(Quantity_2))
			return 0.0;

		return Quantity_2;
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	OpenCloseTradeEnum s_SubmitNewOCOOrder::GetOpenOrClose()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, OpenOrClose) + sizeof(OpenOrClose))
			return TRADE_UNSET;

		return OpenOrClose;
	}
	/*==========================================================================*/
	PartialFillHandlingEnum s_SubmitNewOCOOrder::GetPartialFillHandling()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, PartialFillHandling) + sizeof(PartialFillHandling))
			return PARTIAL_FILL_UNSET;

		return PartialFillHandling;
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewOCOOrderInt), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetClientOrderID_1(const char* NewValue)
	{
		strncpy(ClientOrderID_1, NewValue, sizeof(ClientOrderID_1) - 1);
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetClientOrderID_2(const char* NewValue)
	{
		strncpy(ClientOrderID_2, NewValue, sizeof(ClientOrderID_2) - 1);
	}

	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewOCOOrderInt, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetClientOrderID_1()
	{
		if (Size < offsetof( s_SubmitNewOCOOrderInt, ClientOrderID_1) + sizeof(ClientOrderID_1))
			return "";

		ClientOrderID_1[sizeof(ClientOrderID_1) - 1] = '\0';

		return ClientOrderID_1;
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetClientOrderID_2()
	{
		if (Size < offsetof( s_SubmitNewOCOOrderInt, ClientOrderID_2) + sizeof(ClientOrderID_2))
			return "";

		ClientOrderID_2[sizeof(ClientOrderID_2) - 1] = '\0';

		return ClientOrderID_2;
	}
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetSymbol()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetExchange()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_1()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrderInt, OrderType_1) + sizeof(OrderType_1))
			return ORDER_TYPE_UNSET;

		return OrderType_1;	
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_2()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrderInt, OrderType_2) + sizeof(OrderType_2))
			return ORDER_TYPE_UNSET;

		return OrderType_2;	
	}
	/*==========================================================================*/			 
	BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, BuySell_1) + sizeof(BuySell_1))
			return (BuySellEnum)0;

		return BuySell_1;
	}
	/*==========================================================================*/
	BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, BuySell_2) + sizeof(BuySell_2))
			return (BuySellEnum)0;

		return BuySell_2;
	}
	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewOCOOrderInt::GetTimeInForce()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, TimeInForce) + sizeof(TimeInForce))
			return (TimeInForceEnum)0;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_SubmitNewOCOOrderInt::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}	
	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetParentTriggerClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewOCOOrderInt, ParentTriggerClientOrderID) + sizeof(ParentTriggerClientOrderID))
			return "";

		ParentTriggerClientOrderID[sizeof(ParentTriggerClientOrderID) - 1] = '\0';

		return ParentTriggerClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetParentTriggerClientOrderID(const char* NewValue)
	{
		strncpy(ParentTriggerClientOrderID, NewValue, sizeof(ParentTriggerClientOrderID) - 1);
	}
	/*==========================================================================*/
	uint8_t s_SubmitNewOCOOrderInt::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice1_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price1_1) + sizeof(Price1_1))
			return 0;

		return Price1_1;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice2_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price2_1) + sizeof(Price2_1))
			return 0;

		return Price2_1;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice1_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price1_2) + sizeof(Price1_2))
			return 0;

		return Price1_2;
	}
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice2_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price2_2) + sizeof(Price2_2))
			return 0;

		return Price2_2;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetQuantity_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Quantity_1) + sizeof(Quantity_1))
			return 0;

		return Quantity_1;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetQuantity_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Quantity_2) + sizeof(Quantity_2))
			return 0;

		return Quantity_2;
	}

	/*==========================================================================*/
	const char* s_SubmitNewOCOOrderInt::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewOCOOrderInt, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrderInt::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	float s_SubmitNewOCOOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}
	/*==========================================================================*/
	OpenCloseTradeEnum s_SubmitNewOCOOrderInt::GetOpenOrClose()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, OpenOrClose) + sizeof(OpenOrClose))
			return TRADE_UNSET;

		return OpenOrClose;
	}
	/*==========================================================================*/
	PartialFillHandlingEnum s_SubmitNewOCOOrderInt::GetPartialFillHandling()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, PartialFillHandling) + sizeof(PartialFillHandling))
			return PARTIAL_FILL_UNSET;

		return PartialFillHandling;
	}


	/****************************************************************************/
	// s_OpenOrdersRequest

	/*==========================================================================*/
	uint16_t s_OpenOrdersRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OpenOrdersRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestAllOrders()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestAllOrders) + sizeof(RequestAllOrders))
			return 0;

		return RequestAllOrders;
	}

	/*==========================================================================*/
	const char* s_OpenOrdersRequest::GetServerOrderID()
	{
		if (Size < offsetof( s_OpenOrdersRequest, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_OpenOrdersRequest::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/****************************************************************************/
	// s_HistoricalOrderFillsRequest

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillsRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetNumberOfDays()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, NumberOfDays) + sizeof(NumberOfDays))
			return 0;

		return NumberOfDays;
	}

	/*==========================================================================*/
	const char* s_HistoricalOrderFillsRequest::GetServerOrderID()
	{
		if (Size < offsetof( s_HistoricalOrderFillsRequest, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	const char* s_HistoricalOrderFillsRequest::GetTradeAccount()
	{
		if (Size < offsetof( s_HistoricalOrderFillsRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/****************************************************************************/
	// s_HistoricalOrderFillsReject

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillsReject::GetMessageSize()
	{
		return Size;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsReject::CopyFrom(void * p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillsReject), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsReject::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillsReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}
	/*==========================================================================*/
	const char* s_HistoricalOrderFillsReject::GetRejectText()
	{
		if (Size < offsetof( s_HistoricalOrderFillsReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/****************************************************************************/
	// s_CurrentPositionsRequest

	/*==========================================================================*/
	uint16_t s_CurrentPositionsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CurrentPositionsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_CurrentPositionsRequest::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_CurrentPositionsRequest::GetTradeAccount()
	{
		if (Size < offsetof( s_CurrentPositionsRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_CurrentPositionsRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/****************************************************************************/
	// s_CurrentPositionsRequestReject

	/*==========================================================================*/
	uint16_t s_CurrentPositionsReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CurrentPositionsReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsReject), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_CurrentPositionsReject::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_CurrentPositionsReject::GetRejectText()
	{
		if (Size < offsetof( s_CurrentPositionsReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}
	/*==========================================================================*/
	void s_CurrentPositionsReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}


	/****************************************************************************/
	// s_OrderUpdateReport

	/*==========================================================================*/
	uint16_t s_OrderUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OrderUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OrderUpdate), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetSymbol()
	{
		if (Size < offsetof(s_OrderUpdate, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetExchange()
	{
		if (Size < offsetof(s_OrderUpdate, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetPreviousServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, PreviousServerOrderID) + sizeof(PreviousServerOrderID))
			return "";

		PreviousServerOrderID[sizeof(PreviousServerOrderID) - 1] = '\0';

		return PreviousServerOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetPreviousServerOrderID(const char* NewValue)
	{
		strncpy(PreviousServerOrderID, NewValue, sizeof(PreviousServerOrderID) - 1);
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetClientOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetExchangeOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, ExchangeOrderID) + sizeof(ExchangeOrderID))
			return "";

		ExchangeOrderID[sizeof(ExchangeOrderID) - 1] = '\0';

		return ExchangeOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetExchangeOrderID(const char* NewValue)
	{
		strncpy(ExchangeOrderID, NewValue, sizeof(ExchangeOrderID) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetLastFillExecutionID(const char* NewValue)
	{
		strncpy(LastFillExecutionID, NewValue, sizeof(LastFillExecutionID) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetInfoText(const char* NewValue)
	{
		strncpy(InfoText, NewValue, sizeof(InfoText) - 1);
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetOrderQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetFilledQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, FilledQuantity) + sizeof(FilledQuantity))
			return DBL_MAX;

		return FilledQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetRemainingQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, RemainingQuantity) + sizeof(RemainingQuantity))
			return DBL_MAX;

		return RemainingQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, LastFillQuantity) + sizeof(LastFillQuantity))
			return DBL_MAX;

		return LastFillQuantity;
	}
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetRequestID()
	{
		if (Size < offsetof(s_OrderUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetTotalNumMessages()
	{
		if (Size < offsetof(s_OrderUpdate, TotalNumMessages) + sizeof(TotalNumMessages))
			return 0;

		return TotalNumMessages;
	}

	/*==========================================================================*/
	int32_t s_OrderUpdate::GetMessageNumber()
	{
		if (Size < offsetof(s_OrderUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	OrderStatusEnum s_OrderUpdate::GetOrderStatus()
	{
		if (Size < offsetof(s_OrderUpdate, OrderStatus) + sizeof(OrderStatus))
			return (OrderStatusEnum)0;

		return OrderStatus;
	}
	/*==========================================================================*/
	OrderUpdateReasonEnum s_OrderUpdate::GetOrderUpdateReason()
	{
		if (Size < offsetof(s_OrderUpdate, OrderUpdateReason) + sizeof(OrderUpdateReason))
			return (OrderUpdateReasonEnum)0;

		return OrderUpdateReason;
	}
	/*==========================================================================*/
	OrderTypeEnum s_OrderUpdate::GetOrderType()
	{
		if (Size < offsetof(s_OrderUpdate, OrderType) + sizeof(OrderType))
			return (OrderTypeEnum)0;

		return OrderType;
	}
	/*==========================================================================*/
	BuySellEnum s_OrderUpdate::GetBuySell()
	{
		if (Size < offsetof(s_OrderUpdate, BuySell) + sizeof(BuySell))
			return (BuySellEnum)0;

		return BuySell;
	}
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice1()
	{
		if (Size < offsetof(s_OrderUpdate, Price1) + sizeof(Price1))
			return DBL_MAX;

		return Price1;
	}
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice2()
	{
		if (Size < offsetof(s_OrderUpdate, Price2) + sizeof(Price2))
			return DBL_MAX;

		return Price2;
	}

	/*==========================================================================*/
	TimeInForceEnum s_OrderUpdate::GetTimeInForce()
	{
		if (Size < offsetof(s_OrderUpdate, TimeInForce) + sizeof(TimeInForce))
			return (TimeInForceEnum)0;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_OrderUpdate::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_OrderUpdate, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetAverageFillPrice()
	{
		if (Size < offsetof(s_OrderUpdate, AverageFillPrice) + sizeof(AverageFillPrice))
			return DBL_MAX;

		return AverageFillPrice;
	}
	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillPrice()
	{
		if (Size < offsetof(s_OrderUpdate, LastFillPrice) + sizeof(LastFillPrice))
			return DBL_MAX;

		return LastFillPrice;
	}
	/*==========================================================================*/
	t_DateTime s_OrderUpdate::GetLastFillDateTime() 
	{
		if (Size < offsetof(s_OrderUpdate, LastFillDateTime) + sizeof(LastFillDateTime))
			return 0;

		return LastFillDateTime;
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetLastFillExecutionID()
	{
		if (Size < offsetof(s_OrderUpdate, LastFillExecutionID) + sizeof(LastFillExecutionID))
			return "";

		LastFillExecutionID[sizeof(LastFillExecutionID) - 1] = '\0';

		return LastFillExecutionID;
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetTradeAccount()
	{
		if (Size < offsetof(s_OrderUpdate, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetInfoText()
	{
		if (Size < offsetof(s_OrderUpdate, InfoText) + sizeof(InfoText))
			return "";

		InfoText[sizeof(InfoText) - 1] = '\0';

		return InfoText;
	}
	/*==========================================================================*/	
	uint8_t s_OrderUpdate::GetNoOrders()
	{
		if (Size < offsetof(s_OrderUpdate, NoOrders) + sizeof(NoOrders))
			return 0;

		return NoOrders;
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetParentServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, ParentServerOrderID) + sizeof(ParentServerOrderID))
			return "";

		ParentServerOrderID[sizeof(ParentServerOrderID) - 1] = '\0';

		return ParentServerOrderID;
	}
	/*==========================================================================*/
	void s_OrderUpdate::SetParentServerOrderID(const char* NewValue)
	{
		strncpy(ParentServerOrderID, NewValue, sizeof(ParentServerOrderID) - 1);
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetOCOLinkedOrderServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, OCOLinkedOrderServerOrderID) + sizeof(OCOLinkedOrderServerOrderID))
			return "";

		OCOLinkedOrderServerOrderID[sizeof(OCOLinkedOrderServerOrderID) - 1] = '\0';

		return OCOLinkedOrderServerOrderID;
	}
	/*==========================================================================*/
	void s_OrderUpdate::SetOCOLinkedOrderServerOrderID(const char* NewValue)
	{
		strncpy(OCOLinkedOrderServerOrderID, NewValue, sizeof(OCOLinkedOrderServerOrderID) - 1);
	}
	/*==========================================================================*/
	OpenCloseTradeEnum s_OrderUpdate::GetOpenOrClose()
	{
		if (Size < offsetof(s_OrderUpdate, OpenOrClose) + sizeof(OpenOrClose))
			return TRADE_UNSET;

		return OpenOrClose;
	}
	/*==========================================================================*/
	t_DateTime s_OrderUpdate::GetOrderReceivedDateTime()
	{
		if (Size < offsetof(s_OrderUpdate, OrderReceivedDateTime) + sizeof(OrderReceivedDateTime))
			return 0;

		return OrderReceivedDateTime;
	}
	/*==========================================================================*/
	const char* s_OrderUpdate::GetPreviousClientOrderID()
	{
		if (Size < offsetof(s_OrderUpdate, PreviousClientOrderID) + sizeof(PreviousClientOrderID))
			return "";

		PreviousClientOrderID[sizeof(PreviousClientOrderID) - 1] = '\0';

		return PreviousClientOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetPreviousClientOrderID(const char* NewValue)
	{
		strncpy(PreviousClientOrderID, NewValue, sizeof(PreviousClientOrderID) - 1);
	}

	/*==========================================================================*/
	const char* s_OrderUpdate::GetFreeFormText()
	{
		if (Size < offsetof(s_OrderUpdate, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;
	}

	/*==========================================================================*/
	void s_OrderUpdate::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}

	/****************************************************************************/
	// s_OpenOrdersRequestReject

	/*==========================================================================*/
	uint16_t s_OpenOrdersReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OpenOrdersReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersReject), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_OpenOrdersReject::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	void s_OpenOrdersReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}
	/*==========================================================================*/
	const char* s_OpenOrdersReject::GetRejectText()
	{
		if (Size < offsetof(s_OpenOrdersReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}


	/****************************************************************************/
	// s_HistoricalOrderFillReport

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	const char* s_HistoricalOrderFillResponse::GetSymbol()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_HistoricalOrderFillResponse::GetExchange()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetMessageNumber()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}
	/*==========================================================================*/
	const char* s_HistoricalOrderFillResponse::GetServerOrderID()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/*==========================================================================*/
	const char* s_HistoricalOrderFillResponse::GetTradeAccount()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	const char* s_HistoricalOrderFillResponse::GetUniqueExecutionID()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, UniqueExecutionID) + sizeof(UniqueExecutionID))
			return "";

		UniqueExecutionID[sizeof(UniqueExecutionID) - 1] = '\0';

		return UniqueExecutionID;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillResponse::SetUniqueExecutionID(const char* NewValue)
	{
		strncpy(UniqueExecutionID, NewValue, sizeof(UniqueExecutionID) - 1);
	}
	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetPrice()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Price) + sizeof(Price))
			return 0;

		return Price;
	}
	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetQuantity()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	t_DateTime s_HistoricalOrderFillResponse::GetDateTime() 
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	BuySellEnum s_HistoricalOrderFillResponse::GetBuySell()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, BuySell) + sizeof(BuySell))
			return (BuySellEnum)0;

		return BuySell;
	}

	/*==========================================================================*/
	OpenCloseTradeEnum s_HistoricalOrderFillResponse::GetOpenClose()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, OpenClose) + sizeof(OpenClose))
			return (OpenCloseTradeEnum)0;

		return OpenClose;
	}
	/*==========================================================================*/	
	uint8_t s_HistoricalOrderFillResponse::GetNoOrderFills()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, NoOrderFills) + sizeof(NoOrderFills))
			return 0;

		return NoOrderFills;
	}


	/****************************************************************************/
	// s_PositionReport

	/*==========================================================================*/
	uint16_t s_PositionUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_PositionUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_PositionUpdate), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	void s_PositionUpdate::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	void s_PositionUpdate::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	int32_t s_PositionUpdate::GetRequestID()
	{
		if (Size < offsetof(s_PositionUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	const char* s_PositionUpdate::GetSymbol()
	{
		if (Size < offsetof(s_PositionUpdate, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}
	/*==========================================================================*/
	const char* s_PositionUpdate::GetExchange()
	{
		if (Size < offsetof(s_PositionUpdate, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_PositionUpdate::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	int32_t s_PositionUpdate::GetMessageNumber()
	{
		if (Size < offsetof(s_PositionUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	int32_t s_PositionUpdate::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_PositionUpdate, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}	
	/*==========================================================================*/
	const char* s_PositionUpdate::GetTradeAccount()
	{
		if (Size < offsetof(s_PositionUpdate, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_PositionUpdate::SetPositionIdentifier(const char* NewValue)
	{
		strncpy(PositionIdentifier, NewValue, sizeof(PositionIdentifier) - 1);
	}
	/*==========================================================================*/
	const char* s_PositionUpdate::GetPositionIdentifier()
	{
		if (Size < offsetof(s_PositionUpdate, PositionIdentifier) + sizeof(PositionIdentifier))
			return "";

		PositionIdentifier[sizeof(PositionIdentifier) - 1] = '\0';

		return PositionIdentifier;
	}
	/*==========================================================================*/
	double s_PositionUpdate::GetQuantity()
	{
		if (Size < offsetof(s_PositionUpdate, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}/*==========================================================================*/
	double s_PositionUpdate::GetAveragePrice()
	{
		if (Size < offsetof(s_PositionUpdate, AveragePrice) + sizeof(AveragePrice))
			return 0;

		return AveragePrice;
	}
	/*==========================================================================*/	
	uint8_t s_PositionUpdate::GetNoPositions()
	{
		if (Size < offsetof(s_PositionUpdate, NoPositions) + sizeof(NoPositions))
			return 0;

		return NoPositions;
	}
	/*==========================================================================*/	
	uint8_t s_PositionUpdate::GetUnsolicited()
	{
		if (Size < offsetof(s_PositionUpdate, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}



	/****************************************************************************/
	// s_AccountsRequest

	/*==========================================================================*/
	uint16_t s_TradeAccountsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_TradeAccountsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_TradeAccountsRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_TradeAccountsRequest::GetRequestID()
	{
		if (Size < offsetof(s_TradeAccountsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/****************************************************************************/
	// s_AccountListResponse

	/*==========================================================================*/
	uint16_t s_TradeAccountResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_TradeAccountResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_TradeAccountResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetMessageNumber()
	{
		if (Size < offsetof(s_TradeAccountResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_TradeAccountResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}		
	/*==========================================================================*/
	void s_TradeAccountResponse::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	const char* s_TradeAccountResponse::GetTradeAccount()
	{
		if (Size < offsetof(s_TradeAccountResponse, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetRequestID()
	{
		if (Size < offsetof(s_TradeAccountResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/****************************************************************************/
	// s_ExchangeListRequest

	/*==========================================================================*/
	uint16_t s_ExchangeListRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_ExchangeListRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_ExchangeListRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_ExchangeListRequest::GetRequestID()
	{
		if (Size < offsetof(s_ExchangeListRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_ExchangeListResponse

	/*==========================================================================*/
	uint16_t s_ExchangeListResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_ExchangeListResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_ExchangeListResponse::GetExchange()
	{
		if (Size < offsetof(s_ExchangeListResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	const char* s_ExchangeListResponse::GetDescription()
	{
		if (Size < offsetof(s_ExchangeListResponse, Description) + sizeof(Description))
			return "";

		Description[sizeof(Exchange) - 1] = '\0';

		return Description;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetDescription(const char* NewValue)
	{
		strncpy(Description, NewValue, sizeof(Description) - 1);
	}
	/*==========================================================================*/
	int32_t s_ExchangeListResponse::GetRequestID()
	{
		if (Size < offsetof(s_ExchangeListResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	uint8_t s_ExchangeListResponse::GetIsFinalMessage()
	{
		if (Size < offsetof(s_ExchangeListResponse, IsFinalMessage) + sizeof(IsFinalMessage))
			return 0;

		return IsFinalMessage;
	}


	/****************************************************************************/
	// s_SymbolsForExchangeRequest

	/*==========================================================================*/
	uint16_t s_SymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolsForExchangeRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_SymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_SymbolsForExchangeRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SymbolsForExchangeRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	SecurityTypeEnum s_SymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_UnderlyingSymbolsForExchangeRequest

	/*==========================================================================*/
	uint16_t s_UnderlyingSymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_UnderlyingSymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_UnderlyingSymbolsForExchangeRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_UnderlyingSymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_UnderlyingSymbolsForExchangeRequest::GetExchange()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_UnderlyingSymbolsForExchangeRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	SecurityTypeEnum s_UnderlyingSymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}

	/****************************************************************************/
	// s_SymbolsForUnderlyingRequest

	/*==========================================================================*/
	uint16_t s_SymbolsForUnderlyingRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolsForUnderlyingRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_SymbolsForUnderlyingRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	const char* s_SymbolsForUnderlyingRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::SetUnderlyingSymbol(const char* NewValue)
	{
		strncpy(UnderlyingSymbol, NewValue, sizeof(UnderlyingSymbol) - 1);
	}
	/*==========================================================================*/
	const char* s_SymbolsForUnderlyingRequest::GetUnderlyingSymbol()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, UnderlyingSymbol) + sizeof(UnderlyingSymbol))
			return "";

		UnderlyingSymbol[sizeof(UnderlyingSymbol) - 1] = '\0';

		return UnderlyingSymbol;
	}


	/*==========================================================================*/
	SecurityTypeEnum s_SymbolsForUnderlyingRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SymbolSearchRequest

	/*==========================================================================*/
	uint16_t s_SymbolSearchRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolSearchRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolSearchRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_SymbolSearchRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolSearchRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SymbolSearchRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	const char* s_SymbolSearchRequest::GetSearchText()
	{
		if (Size < offsetof(s_SymbolSearchRequest, SearchText) + sizeof(SearchText))
			return "";

		SearchText[sizeof(SearchText) - 1] = '\0';

		return SearchText;
	}

	/*==========================================================================*/
	void s_SymbolSearchRequest::SetSearchText(const char* NewValue)
	{
		strncpy(SearchText, NewValue, sizeof(SearchText) - 1);
	}

	/*==========================================================================*/
	int32_t s_SymbolSearchRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolSearchRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	SecurityTypeEnum s_SymbolSearchRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolSearchRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}

	/*==========================================================================*/
	SearchTypeEnum s_SymbolSearchRequest::GetSearchType()
	{
		if (Size < offsetof(s_SymbolSearchRequest, SearchType) + sizeof(SearchType))
			return (SearchTypeEnum)0;

		return SearchType;
	}

	/****************************************************************************/
	// s_SecurityDefinitionForSymbolRequest

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionForSymbolRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionForSymbolRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionForSymbolRequest::GetSymbol()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionForSymbolRequest::GetExchange()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	int32_t s_SecurityDefinitionForSymbolRequest::GetRequestID()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_SecurityDefinitionResponse

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionResponse::GetRequestID() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetSymbol()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';  // Ensure that the null terminator exists

		return Symbol;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetExchange()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';  // Ensure that the null terminator exists

		return Exchange;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	SecurityTypeEnum s_SecurityDefinitionResponse::GetSecurityType() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SecurityType) + sizeof(SecurityType))
			return SECURITY_TYPE_UNSET;

		return SecurityType;
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetDescription()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, Description) + sizeof(Description))
			return "";

		Description[sizeof(Description) - 1] = '\0';  // Ensure that the null terminator exists

		return Description;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetDescription(const char* NewValue)
	{
		strncpy(Description, NewValue, sizeof(Description) - 1);
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetMinPriceIncrement() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, MinPriceIncrement) + sizeof(MinPriceIncrement))
			return 0;

		return MinPriceIncrement;
	}

	/*==========================================================================*/
	PriceDisplayFormatEnum s_SecurityDefinitionResponse::GetPriceDisplayFormat() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, PriceDisplayFormat) + sizeof(PriceDisplayFormat))
			return PRICE_DISPLAY_FORMAT_UNSET;

		return PriceDisplayFormat;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetCurrencyValuePerIncrement() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, CurrencyValuePerIncrement) + sizeof(CurrencyValuePerIncrement))
			return 0;

		return CurrencyValuePerIncrement;
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetIsFinalMessage() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, IsFinalMessage) + sizeof(IsFinalMessage))
			return 0;

		return IsFinalMessage;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetFloatToIntPriceMultiplier()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, FloatToIntPriceMultiplier) + sizeof(FloatToIntPriceMultiplier))
			return 1.0f;

		return FloatToIntPriceMultiplier;
	}
	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetIntToFloatPriceDivisor()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, IntToFloatPriceDivisor) + sizeof(IntToFloatPriceDivisor))
			return 1.0f;

		return IntToFloatPriceDivisor;
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetUnderlyingSymbol()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, UnderlyingSymbol) + sizeof(UnderlyingSymbol))
			return "";

		UnderlyingSymbol[sizeof(UnderlyingSymbol) - 1] = '\0';  // Ensure that the null terminator exists

		return UnderlyingSymbol;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetUnderlyingSymbol(const char* NewValue)
	{
		strncpy(UnderlyingSymbol, NewValue, sizeof(UnderlyingSymbol) - 1);
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetUpdatesBidAskOnly() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, UpdatesBidAskOnly) + sizeof(UpdatesBidAskOnly))
			return 0;

		return UpdatesBidAskOnly;
	}


	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetStrikePrice() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, StrikePrice) + sizeof(StrikePrice))
			return 0.0;

		return StrikePrice;
	}


	/*==========================================================================*/
	PutCallEnum s_SecurityDefinitionResponse::GetPutOrCall() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, PutOrCall) + sizeof(PutOrCall))
			return PC_UNSET;

		return PutOrCall;
	}


	/*==========================================================================*/
	uint32_t s_SecurityDefinitionResponse::GetShortInterest() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, ShortInterest) + sizeof(ShortInterest))
			return 0;

		return ShortInterest;
	}


	/*==========================================================================*/
	t_DateTime4Byte s_SecurityDefinitionResponse::GetSecurityExpirationDate() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SecurityExpirationDate) + sizeof(SecurityExpirationDate))
			return 0;

		return SecurityExpirationDate;
	}


	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetBuyRolloverInterest() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, BuyRolloverInterest) + sizeof(BuyRolloverInterest))
			return 0.0;

		return BuyRolloverInterest;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetSellRolloverInterest() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SellRolloverInterest) + sizeof(SellRolloverInterest))
			return 0.0;

		return SellRolloverInterest;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetEarningsPerShare() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, EarningsPerShare) + sizeof(EarningsPerShare))
			return 0.0;

		return EarningsPerShare;
	}

	/*==========================================================================*/
	uint32_t s_SecurityDefinitionResponse::GetSharesOutstanding() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SharesOutstanding) + sizeof(SharesOutstanding))
			return 0;

		return SharesOutstanding;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetIntToFloatQuantityDivisor() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, IntToFloatQuantityDivisor) + sizeof(IntToFloatQuantityDivisor))
			return 0.0;

		return IntToFloatQuantityDivisor;
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetHasMarketDepthData() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, HasMarketDepthData) + sizeof(HasMarketDepthData))
			return 1;

		return HasMarketDepthData;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetDisplayPriceMultiplier() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, DisplayPriceMultiplier) + sizeof(DisplayPriceMultiplier))
			return 1.0;

		return DisplayPriceMultiplier;
	}

	/****************************************************************************/
	// s_SecurityDefinitionReject

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionReject), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint32_t s_SecurityDefinitionReject::GetRequestID()
	{
		return RequestID;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionReject::GetRejectText()
	{
		if (Size < offsetof(s_SecurityDefinitionReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';  // Ensure that the null terminator exists

		return RejectText;
	}

	/****************************************************************************/
	// s_AccountBalanceRequest

	/*==========================================================================*/
	uint16_t s_AccountBalanceRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountBalanceRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountBalanceRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceRequest::GetRequestID()
	{
		return RequestID;
	}

	/*==========================================================================*/
	void s_AccountBalanceRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/*==========================================================================*/
	const char* s_AccountBalanceRequest::GetTradeAccount()
	{
		if (Size < offsetof(s_AccountBalanceRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

		return TradeAccount;
	}

	/****************************************************************************/
	// s_AccountBalanceReject

	/*==========================================================================*/
	uint16_t s_AccountBalanceReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountBalanceReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountBalanceReject), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	uint32_t s_AccountBalanceReject::GetRequestID()
	{
		return RequestID;
	}

	/*==========================================================================*/
	void s_AccountBalanceReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/*==========================================================================*/
	const char* s_AccountBalanceReject::GetRejectText()
	{
		if (Size < offsetof(s_AccountBalanceReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';  // Ensure that the null terminator exists

		return RejectText;
	}


	/****************************************************************************/
	// s_AccountBalanceUpdate

	/*==========================================================================*/
	uint16_t s_AccountBalanceUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountBalanceUpdate), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::SetAccountCurrency(const char* NewValue)
	{
		strncpy(AccountCurrency, NewValue, sizeof(AccountCurrency) - 1);
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	const char* s_AccountBalanceUpdate::GetAccountCurrency()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, AccountCurrency) + sizeof(AccountCurrency))
			return "";

		AccountCurrency[sizeof(AccountCurrency) - 1] = '\0';  // Ensure that the null terminator exists

		return AccountCurrency;
	}
	/*==========================================================================*/
	const char* s_AccountBalanceUpdate::GetTradeAccount()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

		return TradeAccount;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetRequestID()
	{
		return RequestID;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetCashBalance() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, CashBalance) + sizeof(CashBalance))
			return 0;

		return CashBalance;
	}
	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetBalanceAvailableForNewPositions() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, BalanceAvailableForNewPositions) + sizeof(BalanceAvailableForNewPositions))
			return 0;

		return BalanceAvailableForNewPositions;
	}
	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetSecuritiesValue() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, SecuritiesValue) + sizeof(SecuritiesValue))
			return 0;

		return SecuritiesValue;
	}
	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetMarginRequirement() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, MarginRequirement) + sizeof(MarginRequirement))
			return 0;

		return MarginRequirement;
	}
	
	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetTotalNumberMessages() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetMessageNumber() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	uint8_t s_AccountBalanceUpdate::GetNoAccountBalances() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, NoAccountBalances) + sizeof(NoAccountBalances))
			return 0;

		return NoAccountBalances;
	}

	/*==========================================================================*/
	uint8_t s_AccountBalanceUpdate::GetUnsolicited() const
	{
		if (Size < offsetof(s_AccountBalanceUpdate, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}


	/****************************************************************************/
	// s_UserMessage

	/*==========================================================================*/
	uint16_t s_UserMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_UserMessage::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_UserMessage), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	void s_UserMessage::SetUserMessage(const char* NewValue)
	{
		strncpy(UserMessage, NewValue, sizeof(UserMessage) - 1);
	}
	/*==========================================================================*/
	const char* s_UserMessage::GetUserMessage()
	{
		if (Size < offsetof(s_UserMessage, UserMessage) + sizeof(UserMessage))
			return "";

		UserMessage[sizeof(UserMessage) - 1] = '\0';  // Ensure that the null terminator exists

		return UserMessage;
	}

	/*==========================================================================*/
	uint8_t s_UserMessage::GetIsPopupMessage()
	{
		if (Size < offsetof(s_UserMessage, IsPopupMessage) + sizeof(IsPopupMessage))
			return 0;

		return IsPopupMessage;
	}


	/****************************************************************************/
	// s_GeneralLogMessage

	/*==========================================================================*/
	uint16_t s_GeneralLogMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_GeneralLogMessage::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_GeneralLogMessage), *static_cast<uint16_t*>( p_SourceData) ));
	}


	/*==========================================================================*/
	const char* s_GeneralLogMessage::GetMessageText()
	{
		if (Size < offsetof(s_GeneralLogMessage, MessageText) + sizeof(MessageText))
			return "";

		MessageText[sizeof(MessageText) - 1] = '\0';

		return MessageText;
	}

	/*==========================================================================*/
	void s_GeneralLogMessage::SetMessageText(const char* NewValue)
	{
		strncpy(MessageText, NewValue, sizeof(MessageText) - 1);
	}

	/****************************************************************************/
	// s_HistoricalPriceDataRequest

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRequest), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_HistoricalPriceDataRequest::GetSymbol()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_HistoricalPriceDataRequest::GetExchange()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRequest::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRequest::GetMaxDaysToReturn()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, MaxDaysToReturn) + sizeof(MaxDaysToReturn))
			return 0;

		return MaxDaysToReturn;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRequest::GetEndDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, EndDateTime) + sizeof(EndDateTime))
			return 0;

		return EndDateTime;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRequest::GetStartDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}
	/*==========================================================================*/
	HistoricalDataIntervalEnum s_HistoricalPriceDataRequest::GetRecordInterval()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RecordInterval) + sizeof(RecordInterval))
			return (HistoricalDataIntervalEnum)0;

		return RecordInterval;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetUseZLibCompression()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, UseZLibCompression) + sizeof(UseZLibCompression))
			return 0;

		return UseZLibCompression;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetRequestDividendAdjustedStockData()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RequestDividendAdjustedStockData) + sizeof(RequestDividendAdjustedStockData))
			return 0;

		return RequestDividendAdjustedStockData;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetFlag_1()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Flag_1) + sizeof(Flag_1))
			return 0;

		return Flag_1;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataHeaderResponse

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataResponseHeader::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataResponseHeader::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataResponseHeader), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataResponseHeader::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseHeader, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	HistoricalDataIntervalEnum s_HistoricalPriceDataResponseHeader::GetRecordInterval()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseHeader, RecordInterval) + sizeof(RecordInterval))
			return (HistoricalDataIntervalEnum)0;

		return RecordInterval;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataResponseHeader::GetUseZLibCompression()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseHeader, UseZLibCompression) + sizeof(UseZLibCompression))
			return 0;

		return UseZLibCompression;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataResponseHeader::GetNoRecordsToReturn()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseHeader, NoRecordsToReturn) + sizeof(NoRecordsToReturn))
			return 0;

		return NoRecordsToReturn;
	}
	/*==========================================================================*/
	float s_HistoricalPriceDataResponseHeader::GetIntToFloatPriceDivisor()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseHeader, IntToFloatPriceDivisor) + sizeof(IntToFloatPriceDivisor))
			return 1.0f;

		return IntToFloatPriceDivisor;
	}

	/****************************************************************************/
	// s_HistoricalPriceDataReject

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataReject),*static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	const char* s_HistoricalPriceDataReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDataReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	HistoricalPriceDataRejectReasonCodeEnum s_HistoricalPriceDataReject::GetRejectReasonCode()
	{
		if (Size < offsetof(s_HistoricalPriceDataReject, RejectReasonCode) + sizeof(RejectReasonCode))
			return HPDR_UNSET;

		return RejectReasonCode;
	}

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataReject::GetRetryTimeInSeconds()
	{
		if (Size < offsetof(s_HistoricalPriceDataReject, RetryTimeInSeconds) + sizeof(RetryTimeInSeconds))
			return 0;

		return RetryTimeInSeconds;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataReject::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}



	/****************************************************************************/
	// s_HistoricalPriceDataRecordResponse

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRecordResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRecordResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRecordResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetOpenPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, OpenPrice) + sizeof(OpenPrice))
			return 0;

		return OpenPrice;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetHighPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, HighPrice) + sizeof(HighPrice))
			return 0;

		return HighPrice;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetLowPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, LowPrice) + sizeof(LowPrice))
			return 0;

		return LowPrice;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetLastPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, LastPrice) + sizeof(LastPrice))
			return 0;

		return LastPrice;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRecordResponse::GetOpenInterest()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}
	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRecordResponse::GetNumTrades()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, NumTrades) + sizeof(NumTrades))
			return 0;

		return NumTrades;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetBidVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, BidVolume) + sizeof(BidVolume))
			return 0;

		return BidVolume;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetAskVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, AskVolume) + sizeof(AskVolume))
			return 0;

		return AskVolume;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRecordResponse::GetStartDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRecordResponse::GetIsFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, IsFinalRecord) + sizeof(IsFinalRecord))
			return 0;

		return IsFinalRecord;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataTickRecordResponse

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataTickRecordResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataTickRecordResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataTickRecordResponse), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataTickRecordResponse::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_HistoricalPriceDataTickRecordResponse::GetDateTime()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataTickRecordResponse::GetPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, Price) + sizeof(Price))
			return 0;

		return Price;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataTickRecordResponse::GetVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/
	AtBidOrAskEnum s_HistoricalPriceDataTickRecordResponse::GetAtBidOrAsk()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, AtBidOrAsk) + sizeof(AtBidOrAsk))
			return BID_ASK_UNSET;

		return AtBidOrAsk;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataTickRecordResponse::GetIsFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, IsFinalRecord) + sizeof(IsFinalRecord))
			return 0;

		return IsFinalRecord;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataRecordResponse_Int

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRecordResponse_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRecordResponse_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRecordResponse_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetOpenPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, OpenPrice) + sizeof(OpenPrice))
			return 0;

		return OpenPrice;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetHighPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, HighPrice) + sizeof(HighPrice))
			return 0;

		return HighPrice;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetLowPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, LowPrice) + sizeof(LowPrice))
			return 0;

		return LowPrice;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetLastPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, LastPrice) + sizeof(LastPrice))
			return 0;

		return LastPrice;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRecordResponse_Int::GetOpenInterest()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}
	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRecordResponse_Int::GetNumTrades()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, NumTrades) + sizeof(NumTrades))
			return 0;

		return NumTrades;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetBidVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, BidVolume) + sizeof(BidVolume))
			return 0;

		return BidVolume;
	}
	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRecordResponse_Int::GetAskVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, AskVolume) + sizeof(AskVolume))
			return 0;

		return AskVolume;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRecordResponse_Int::GetStartDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRecordResponse_Int::GetIsFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse_Int, IsFinalRecord) + sizeof(IsFinalRecord))
			return 0;

		return IsFinalRecord;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataTickRecordResponse_Int

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataTickRecordResponse_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataTickRecordResponse_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataTickRecordResponse_Int), *static_cast<uint16_t*>( p_SourceData) ));
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataTickRecordResponse_Int::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_HistoricalPriceDataTickRecordResponse_Int::GetDateTime()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataTickRecordResponse_Int::GetPrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataTickRecordResponse_Int::GetVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}

	/*==========================================================================*/
	AtBidOrAskEnum s_HistoricalPriceDataTickRecordResponse_Int::GetAtBidOrAsk()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, AtBidOrAsk) + sizeof(AtBidOrAsk))
			return BID_ASK_UNSET;

		return AtBidOrAsk;
	}

	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataTickRecordResponse_Int::GetIsFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse_Int, IsFinalRecord) + sizeof(IsFinalRecord))
			return 0;

		return IsFinalRecord;
	}

	/****************************************************************************/
	// s_HistoricalPriceDataResponseTrailer

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataResponseTrailer::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataResponseTrailer::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataResponseTrailer), *static_cast<uint16_t*>( p_SourceData)));
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataResponseTrailer::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseTrailer, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	t_DateTimeWithMilliseconds s_HistoricalPriceDataResponseTrailer::GetFinalRecordLastDateTime()
	{
		if (Size < offsetof(s_HistoricalPriceDataResponseTrailer, FinalRecordLastDateTime) + sizeof(FinalRecordLastDateTime))
			return 0;

		return FinalRecordLastDateTime;
	}

	/*==========================================================================*/
}