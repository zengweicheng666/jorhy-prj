/* soapDeviceBindingProxy.h
   Generated by gSOAP 2.8.0 from Onvif.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapDeviceBindingProxy_H
#define soapDeviceBindingProxy_H
#include "soapH.h"
class DeviceBinding
{   public:
	/// Runtime engine context allocated in constructor
	struct soap *soap;
	/// Endpoint URL of service 'DeviceBinding' (change as needed)
	const char *endpoint;
	/// Constructor allocates soap engine context, sets default endpoint URL, and sets namespace mapping table
	DeviceBinding()
	{ soap = soap_new(); endpoint = "http://localhost:80"; if (soap && !soap->namespaces) { static const struct Namespace namespaces[] = 
{
	{"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
	{"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"wsa5", "http://www.w3.org/2005/08/addressing", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL},
	{"c14n", "http://www.w3.org/2001/10/xml-exc-c14n#", NULL, NULL},
	{"wsu", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd", NULL, NULL},
	{"ds", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL},
	{"wsse", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd", "http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd", NULL},
	{"ns5", "http://docs.oasis-open.org/wsrf/r-2", NULL, NULL},
	{"ns6", "http://schemas.xmlsoap.org/ws/2005/04/discovery", NULL, NULL},
	{"xmime", "http://tempuri.org/xmime.xsd", NULL, NULL},
	{"xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL},
	{"tt", "http://www.onvif.org/ver10/schema", NULL, NULL},
	{"ns2", "http://docs.oasis-open.org/wsrf/bf-2", NULL, NULL},
	{"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL, NULL},
	{"ns3", "http://docs.oasis-open.org/wsn/t-1", NULL, NULL},
	{"ns10", "http://www.onvif.org/ver10/events/wsdl/PullPointSubscriptionBinding", NULL, NULL},
	{"ns11", "http://www.onvif.org/ver10/events/wsdl/EventBinding", NULL, NULL},
	{"tev", "http://www.onvif.org/ver10/events/wsdl", NULL, NULL},
	{"ns12", "http://www.onvif.org/ver10/events/wsdl/SubscriptionManagerBinding", NULL, NULL},
	{"ns13", "http://www.onvif.org/ver10/events/wsdl/NotificationProducerBinding", NULL, NULL},
	{"ns14", "http://www.onvif.org/ver10/events/wsdl/NotificationConsumerBinding", NULL, NULL},
	{"ns15", "http://www.onvif.org/ver10/events/wsdl/PullPointBinding", NULL, NULL},
	{"ns16", "http://www.onvif.org/ver10/events/wsdl/CreatePullPointBinding", NULL, NULL},
	{"ns17", "http://www.onvif.org/ver10/events/wsdl/PausableSubscriptionManagerBinding", NULL, NULL},
	{"ns1", "http://docs.oasis-open.org/wsn/b-2", NULL, NULL},
	{"ns18", "http://www.onvif.org/ver10/network/wsdl/RemoteDiscoveryBinding", NULL, NULL},
	{"ns19", "http://www.onvif.org/ver10/network/wsdl/DiscoveryLookupBinding", NULL, NULL},
	{"dn", "http://www.onvif.org/ver10/network/wsdl", NULL, NULL},
	{"ns8", "http://www.onvif.org/ver20/analytics/wsdl/RuleEngineBinding", NULL, NULL},
	{"ns9", "http://www.onvif.org/ver20/analytics/wsdl/AnalyticsEngineBinding", NULL, NULL},
	{"tan", "http://www.onvif.org/ver20/analytics/wsdl", NULL, NULL},
	{"tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL},
	{"timg", "http://www.onvif.org/ver20/imaging/wsdl", NULL, NULL},
	{"tptz", "http://www.onvif.org/ver20/ptz/wsdl", NULL, NULL},
	{"trt", "http://www.onvif.org/ver10/media/wsdl", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap->namespaces = namespaces; } };
	/// Destructor frees deserialized data and soap engine context
	virtual ~DeviceBinding() { if (soap) { soap_destroy(soap); soap_end(soap); soap_free(soap); } };
	/// Invoke 'GetDeviceInformation' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse) { return soap ? soap_call___tds__GetDeviceInformation(soap, endpoint, NULL, tds__GetDeviceInformation, tds__GetDeviceInformationResponse) : SOAP_EOM; };
	/// Invoke 'SetSystemDateAndTime' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetSystemDateAndTime(_tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse) { return soap ? soap_call___tds__SetSystemDateAndTime(soap, endpoint, NULL, tds__SetSystemDateAndTime, tds__SetSystemDateAndTimeResponse) : SOAP_EOM; };
	/// Invoke 'GetSystemDateAndTime' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetSystemDateAndTime(_tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse) { return soap ? soap_call___tds__GetSystemDateAndTime(soap, endpoint, NULL, tds__GetSystemDateAndTime, tds__GetSystemDateAndTimeResponse) : SOAP_EOM; };
	/// Invoke 'SetSystemFactoryDefault' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetSystemFactoryDefault(_tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse) { return soap ? soap_call___tds__SetSystemFactoryDefault(soap, endpoint, NULL, tds__SetSystemFactoryDefault, tds__SetSystemFactoryDefaultResponse) : SOAP_EOM; };
	/// Invoke 'UpgradeSystemFirmware' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__UpgradeSystemFirmware(_tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse) { return soap ? soap_call___tds__UpgradeSystemFirmware(soap, endpoint, NULL, tds__UpgradeSystemFirmware, tds__UpgradeSystemFirmwareResponse) : SOAP_EOM; };
	/// Invoke 'SystemReboot' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SystemReboot(_tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse *tds__SystemRebootResponse) { return soap ? soap_call___tds__SystemReboot(soap, endpoint, NULL, tds__SystemReboot, tds__SystemRebootResponse) : SOAP_EOM; };
	/// Invoke 'RestoreSystem' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__RestoreSystem(_tds__RestoreSystem *tds__RestoreSystem, _tds__RestoreSystemResponse *tds__RestoreSystemResponse) { return soap ? soap_call___tds__RestoreSystem(soap, endpoint, NULL, tds__RestoreSystem, tds__RestoreSystemResponse) : SOAP_EOM; };
	/// Invoke 'GetSystemBackup' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetSystemBackup(_tds__GetSystemBackup *tds__GetSystemBackup, _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse) { return soap ? soap_call___tds__GetSystemBackup(soap, endpoint, NULL, tds__GetSystemBackup, tds__GetSystemBackupResponse) : SOAP_EOM; };
	/// Invoke 'GetSystemLog' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetSystemLog(_tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse *tds__GetSystemLogResponse) { return soap ? soap_call___tds__GetSystemLog(soap, endpoint, NULL, tds__GetSystemLog, tds__GetSystemLogResponse) : SOAP_EOM; };
	/// Invoke 'GetSystemSupportInformation' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetSystemSupportInformation(_tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse) { return soap ? soap_call___tds__GetSystemSupportInformation(soap, endpoint, NULL, tds__GetSystemSupportInformation, tds__GetSystemSupportInformationResponse) : SOAP_EOM; };
	/// Invoke 'GetScopes' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetScopes(_tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse *tds__GetScopesResponse) { return soap ? soap_call___tds__GetScopes(soap, endpoint, NULL, tds__GetScopes, tds__GetScopesResponse) : SOAP_EOM; };
	/// Invoke 'SetScopes' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetScopes(_tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse *tds__SetScopesResponse) { return soap ? soap_call___tds__SetScopes(soap, endpoint, NULL, tds__SetScopes, tds__SetScopesResponse) : SOAP_EOM; };
	/// Invoke 'AddScopes' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__AddScopes(_tds__AddScopes *tds__AddScopes, _tds__AddScopesResponse *tds__AddScopesResponse) { return soap ? soap_call___tds__AddScopes(soap, endpoint, NULL, tds__AddScopes, tds__AddScopesResponse) : SOAP_EOM; };
	/// Invoke 'RemoveScopes' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__RemoveScopes(_tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse *tds__RemoveScopesResponse) { return soap ? soap_call___tds__RemoveScopes(soap, endpoint, NULL, tds__RemoveScopes, tds__RemoveScopesResponse) : SOAP_EOM; };
	/// Invoke 'GetDiscoveryMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetDiscoveryMode(_tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse) { return soap ? soap_call___tds__GetDiscoveryMode(soap, endpoint, NULL, tds__GetDiscoveryMode, tds__GetDiscoveryModeResponse) : SOAP_EOM; };
	/// Invoke 'SetDiscoveryMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetDiscoveryMode(_tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse) { return soap ? soap_call___tds__SetDiscoveryMode(soap, endpoint, NULL, tds__SetDiscoveryMode, tds__SetDiscoveryModeResponse) : SOAP_EOM; };
	/// Invoke 'GetRemoteDiscoveryMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetRemoteDiscoveryMode(_tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse) { return soap ? soap_call___tds__GetRemoteDiscoveryMode(soap, endpoint, NULL, tds__GetRemoteDiscoveryMode, tds__GetRemoteDiscoveryModeResponse) : SOAP_EOM; };
	/// Invoke 'SetRemoteDiscoveryMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetRemoteDiscoveryMode(_tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse) { return soap ? soap_call___tds__SetRemoteDiscoveryMode(soap, endpoint, NULL, tds__SetRemoteDiscoveryMode, tds__SetRemoteDiscoveryModeResponse) : SOAP_EOM; };
	/// Invoke 'GetDPAddresses' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetDPAddresses(_tds__GetDPAddresses *tds__GetDPAddresses, _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse) { return soap ? soap_call___tds__GetDPAddresses(soap, endpoint, NULL, tds__GetDPAddresses, tds__GetDPAddressesResponse) : SOAP_EOM; };
	/// Invoke 'GetUsers' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetUsers(_tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse *tds__GetUsersResponse) { return soap ? soap_call___tds__GetUsers(soap, endpoint, NULL, tds__GetUsers, tds__GetUsersResponse) : SOAP_EOM; };
	/// Invoke 'CreateUsers' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__CreateUsers(_tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse *tds__CreateUsersResponse) { return soap ? soap_call___tds__CreateUsers(soap, endpoint, NULL, tds__CreateUsers, tds__CreateUsersResponse) : SOAP_EOM; };
	/// Invoke 'DeleteUsers' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__DeleteUsers(_tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse *tds__DeleteUsersResponse) { return soap ? soap_call___tds__DeleteUsers(soap, endpoint, NULL, tds__DeleteUsers, tds__DeleteUsersResponse) : SOAP_EOM; };
	/// Invoke 'SetUser' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetUser(_tds__SetUser *tds__SetUser, _tds__SetUserResponse *tds__SetUserResponse) { return soap ? soap_call___tds__SetUser(soap, endpoint, NULL, tds__SetUser, tds__SetUserResponse) : SOAP_EOM; };
	/// Invoke 'GetWsdlUrl' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetWsdlUrl(_tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse) { return soap ? soap_call___tds__GetWsdlUrl(soap, endpoint, NULL, tds__GetWsdlUrl, tds__GetWsdlUrlResponse) : SOAP_EOM; };
	/// Invoke 'GetCapabilities' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse) { return soap ? soap_call___tds__GetCapabilities(soap, endpoint, NULL, tds__GetCapabilities, tds__GetCapabilitiesResponse) : SOAP_EOM; };
	/// Invoke 'SetDPAddresses' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetDPAddresses(_tds__SetDPAddresses *tds__SetDPAddresses, _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse) { return soap ? soap_call___tds__SetDPAddresses(soap, endpoint, NULL, tds__SetDPAddresses, tds__SetDPAddressesResponse) : SOAP_EOM; };
	/// Invoke 'GetHostname' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetHostname(_tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse *tds__GetHostnameResponse) { return soap ? soap_call___tds__GetHostname(soap, endpoint, NULL, tds__GetHostname, tds__GetHostnameResponse) : SOAP_EOM; };
	/// Invoke 'SetHostname' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetHostname(_tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse *tds__SetHostnameResponse) { return soap ? soap_call___tds__SetHostname(soap, endpoint, NULL, tds__SetHostname, tds__SetHostnameResponse) : SOAP_EOM; };
	/// Invoke 'GetDNS' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetDNS(_tds__GetDNS *tds__GetDNS, _tds__GetDNSResponse *tds__GetDNSResponse) { return soap ? soap_call___tds__GetDNS(soap, endpoint, NULL, tds__GetDNS, tds__GetDNSResponse) : SOAP_EOM; };
	/// Invoke 'SetDNS' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetDNS(_tds__SetDNS *tds__SetDNS, _tds__SetDNSResponse *tds__SetDNSResponse) { return soap ? soap_call___tds__SetDNS(soap, endpoint, NULL, tds__SetDNS, tds__SetDNSResponse) : SOAP_EOM; };
	/// Invoke 'GetNTP' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetNTP(_tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse *tds__GetNTPResponse) { return soap ? soap_call___tds__GetNTP(soap, endpoint, NULL, tds__GetNTP, tds__GetNTPResponse) : SOAP_EOM; };
	/// Invoke 'SetNTP' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetNTP(_tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse *tds__SetNTPResponse) { return soap ? soap_call___tds__SetNTP(soap, endpoint, NULL, tds__SetNTP, tds__SetNTPResponse) : SOAP_EOM; };
	/// Invoke 'GetDynamicDNS' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetDynamicDNS(_tds__GetDynamicDNS *tds__GetDynamicDNS, _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse) { return soap ? soap_call___tds__GetDynamicDNS(soap, endpoint, NULL, tds__GetDynamicDNS, tds__GetDynamicDNSResponse) : SOAP_EOM; };
	/// Invoke 'SetDynamicDNS' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetDynamicDNS(_tds__SetDynamicDNS *tds__SetDynamicDNS, _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse) { return soap ? soap_call___tds__SetDynamicDNS(soap, endpoint, NULL, tds__SetDynamicDNS, tds__SetDynamicDNSResponse) : SOAP_EOM; };
	/// Invoke 'GetNetworkInterfaces' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetNetworkInterfaces(_tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse) { return soap ? soap_call___tds__GetNetworkInterfaces(soap, endpoint, NULL, tds__GetNetworkInterfaces, tds__GetNetworkInterfacesResponse) : SOAP_EOM; };
	/// Invoke 'SetNetworkInterfaces' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetNetworkInterfaces(_tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse) { return soap ? soap_call___tds__SetNetworkInterfaces(soap, endpoint, NULL, tds__SetNetworkInterfaces, tds__SetNetworkInterfacesResponse) : SOAP_EOM; };
	/// Invoke 'GetNetworkProtocols' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetNetworkProtocols(_tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse) { return soap ? soap_call___tds__GetNetworkProtocols(soap, endpoint, NULL, tds__GetNetworkProtocols, tds__GetNetworkProtocolsResponse) : SOAP_EOM; };
	/// Invoke 'SetNetworkProtocols' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetNetworkProtocols(_tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse) { return soap ? soap_call___tds__SetNetworkProtocols(soap, endpoint, NULL, tds__SetNetworkProtocols, tds__SetNetworkProtocolsResponse) : SOAP_EOM; };
	/// Invoke 'GetNetworkDefaultGateway' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetNetworkDefaultGateway(_tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse) { return soap ? soap_call___tds__GetNetworkDefaultGateway(soap, endpoint, NULL, tds__GetNetworkDefaultGateway, tds__GetNetworkDefaultGatewayResponse) : SOAP_EOM; };
	/// Invoke 'SetNetworkDefaultGateway' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetNetworkDefaultGateway(_tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse) { return soap ? soap_call___tds__SetNetworkDefaultGateway(soap, endpoint, NULL, tds__SetNetworkDefaultGateway, tds__SetNetworkDefaultGatewayResponse) : SOAP_EOM; };
	/// Invoke 'GetZeroConfiguration' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetZeroConfiguration(_tds__GetZeroConfiguration *tds__GetZeroConfiguration, _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse) { return soap ? soap_call___tds__GetZeroConfiguration(soap, endpoint, NULL, tds__GetZeroConfiguration, tds__GetZeroConfigurationResponse) : SOAP_EOM; };
	/// Invoke 'SetZeroConfiguration' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetZeroConfiguration(_tds__SetZeroConfiguration *tds__SetZeroConfiguration, _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse) { return soap ? soap_call___tds__SetZeroConfiguration(soap, endpoint, NULL, tds__SetZeroConfiguration, tds__SetZeroConfigurationResponse) : SOAP_EOM; };
	/// Invoke 'GetIPAddressFilter' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetIPAddressFilter(_tds__GetIPAddressFilter *tds__GetIPAddressFilter, _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse) { return soap ? soap_call___tds__GetIPAddressFilter(soap, endpoint, NULL, tds__GetIPAddressFilter, tds__GetIPAddressFilterResponse) : SOAP_EOM; };
	/// Invoke 'SetIPAddressFilter' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetIPAddressFilter(_tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse) { return soap ? soap_call___tds__SetIPAddressFilter(soap, endpoint, NULL, tds__SetIPAddressFilter, tds__SetIPAddressFilterResponse) : SOAP_EOM; };
	/// Invoke 'AddIPAddressFilter' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__AddIPAddressFilter(_tds__AddIPAddressFilter *tds__AddIPAddressFilter, _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse) { return soap ? soap_call___tds__AddIPAddressFilter(soap, endpoint, NULL, tds__AddIPAddressFilter, tds__AddIPAddressFilterResponse) : SOAP_EOM; };
	/// Invoke 'RemoveIPAddressFilter' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__RemoveIPAddressFilter(_tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse) { return soap ? soap_call___tds__RemoveIPAddressFilter(soap, endpoint, NULL, tds__RemoveIPAddressFilter, tds__RemoveIPAddressFilterResponse) : SOAP_EOM; };
	/// Invoke 'GetAccessPolicy' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetAccessPolicy(_tds__GetAccessPolicy *tds__GetAccessPolicy, _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse) { return soap ? soap_call___tds__GetAccessPolicy(soap, endpoint, NULL, tds__GetAccessPolicy, tds__GetAccessPolicyResponse) : SOAP_EOM; };
	/// Invoke 'SetAccessPolicy' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetAccessPolicy(_tds__SetAccessPolicy *tds__SetAccessPolicy, _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse) { return soap ? soap_call___tds__SetAccessPolicy(soap, endpoint, NULL, tds__SetAccessPolicy, tds__SetAccessPolicyResponse) : SOAP_EOM; };
	/// Invoke 'CreateCertificate' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__CreateCertificate(_tds__CreateCertificate *tds__CreateCertificate, _tds__CreateCertificateResponse *tds__CreateCertificateResponse) { return soap ? soap_call___tds__CreateCertificate(soap, endpoint, NULL, tds__CreateCertificate, tds__CreateCertificateResponse) : SOAP_EOM; };
	/// Invoke 'GetCertificates' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetCertificates(_tds__GetCertificates *tds__GetCertificates, _tds__GetCertificatesResponse *tds__GetCertificatesResponse) { return soap ? soap_call___tds__GetCertificates(soap, endpoint, NULL, tds__GetCertificates, tds__GetCertificatesResponse) : SOAP_EOM; };
	/// Invoke 'GetCertificatesStatus' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetCertificatesStatus(_tds__GetCertificatesStatus *tds__GetCertificatesStatus, _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse) { return soap ? soap_call___tds__GetCertificatesStatus(soap, endpoint, NULL, tds__GetCertificatesStatus, tds__GetCertificatesStatusResponse) : SOAP_EOM; };
	/// Invoke 'SetCertificatesStatus' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetCertificatesStatus(_tds__SetCertificatesStatus *tds__SetCertificatesStatus, _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse) { return soap ? soap_call___tds__SetCertificatesStatus(soap, endpoint, NULL, tds__SetCertificatesStatus, tds__SetCertificatesStatusResponse) : SOAP_EOM; };
	/// Invoke 'DeleteCertificates' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__DeleteCertificates(_tds__DeleteCertificates *tds__DeleteCertificates, _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse) { return soap ? soap_call___tds__DeleteCertificates(soap, endpoint, NULL, tds__DeleteCertificates, tds__DeleteCertificatesResponse) : SOAP_EOM; };
	/// Invoke 'GetPkcs10Request' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetPkcs10Request(_tds__GetPkcs10Request *tds__GetPkcs10Request, _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse) { return soap ? soap_call___tds__GetPkcs10Request(soap, endpoint, NULL, tds__GetPkcs10Request, tds__GetPkcs10RequestResponse) : SOAP_EOM; };
	/// Invoke 'LoadCertificates' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__LoadCertificates(_tds__LoadCertificates *tds__LoadCertificates, _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse) { return soap ? soap_call___tds__LoadCertificates(soap, endpoint, NULL, tds__LoadCertificates, tds__LoadCertificatesResponse) : SOAP_EOM; };
	/// Invoke 'GetClientCertificateMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetClientCertificateMode(_tds__GetClientCertificateMode *tds__GetClientCertificateMode, _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse) { return soap ? soap_call___tds__GetClientCertificateMode(soap, endpoint, NULL, tds__GetClientCertificateMode, tds__GetClientCertificateModeResponse) : SOAP_EOM; };
	/// Invoke 'SetClientCertificateMode' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetClientCertificateMode(_tds__SetClientCertificateMode *tds__SetClientCertificateMode, _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse) { return soap ? soap_call___tds__SetClientCertificateMode(soap, endpoint, NULL, tds__SetClientCertificateMode, tds__SetClientCertificateModeResponse) : SOAP_EOM; };
	/// Invoke 'GetRelayOutputs' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__GetRelayOutputs(_tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) { return soap ? soap_call___tds__GetRelayOutputs(soap, endpoint, NULL, tds__GetRelayOutputs, tds__GetRelayOutputsResponse) : SOAP_EOM; };
	/// Invoke 'SetRelayOutputSettings' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetRelayOutputSettings(_tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse) { return soap ? soap_call___tds__SetRelayOutputSettings(soap, endpoint, NULL, tds__SetRelayOutputSettings, tds__SetRelayOutputSettingsResponse) : SOAP_EOM; };
	/// Invoke 'SetRelayOutputState' of service 'DeviceBinding' and return error code (or SOAP_OK)
	virtual int __tds__SetRelayOutputState(_tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) { return soap ? soap_call___tds__SetRelayOutputState(soap, endpoint, NULL, tds__SetRelayOutputState, tds__SetRelayOutputStateResponse) : SOAP_EOM; };
};
#endif
