/*
 ******************************************************************************
 *                     IPNET_CONFIG.H
 *
 *   Document no: @(#) $Name: VXWORKS_ITER18A_FRZ10 $ $RCSfile: ipnet_config.h,v $ $Revision: 1.177.12.1.4.4 $
 *   $Source: /home/interpeak/CVSRoot/ipnet2/config/ipnet_config.h,v $
 *   $Author: dbush $ $Date: 2010-07-23 17:15:24 $
 *   $State: Exp $ $Locker:  $
 *
 *   INTERPEAK_COPYRIGHT_STRING
 *   Design and implementation by Kenneth Jonsson <kenneth@interpeak.se>
 ******************************************************************************
 */

#ifndef IPNET_CONFIG_H
#define IPNET_CONFIG_H

/*
 ****************************************************************************
 * 1                    DESCRIPTION
 ****************************************************************************
 *
 * Configuration for IPNET. Parameters that are macros can only be changed
 * before compiling, variables can be changed before compiling and linking.
 */

/*
 ****************************************************************************
 * 2                    INCLUDE FILES
 ****************************************************************************
 */

#include <ipcom_config.h>

#include <ipcom_type.h>
#include <ipcom_cstyle.h>

#ifdef __cplusplus
extern "C" {
#endif


/*
 ****************************************************************************
 * 3                    TYPES
 ****************************************************************************
 */

/* Forward delcaration */
struct Ipnet_netif_struct;

/* Packet pool entry */
typedef struct Ipnet_conf_pkt_pool_struct
{
    int     count;  /* Number of packet of this size */
    int     mtu;    /* The size of the packets in this pool */
    int     mprio;  /* The minimum priority needed to be allowed to allocate this pkt */
}
Ipnet_conf_pkt_pool;

/* Link layer initialization function */
typedef struct Ipnet_conf_link_layer_init_struct
{
    int type;   /* Type of link layer (IP_IFT_xxx) */
    int (*init_func)(struct Ipnet_netif_struct *netif);
}
Ipnet_conf_link_layer_init;

/*
 ****************************************************************************
 * 4                       CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPCOM_SYSLOG_PRIORITY
 *===========================================================================
 * Default syslog priority.
 */
#ifdef IP_DEBUG
#define IPNET_SYSLOG_PRIORITY  IPCOM_LOG_DEBUG /* (see ipcom_syslog.h) */
#else
#define IPNET_SYSLOG_PRIORITY  IPCOM_LOG_WARNING
#endif


/*
 *===========================================================================
 *                         IPNET DEBUG/ASSERT
 *===========================================================================
 * Define IPNET_ASSERT and/or IPNET_DEBUG to debug IPNET.
 */
#ifdef IP_ASSERT
#define IPNET_ASSERT
#endif

#ifdef IP_DEBUG
#define IPNET_DEBUG
#endif


/*
 ****************************************************************************
 *                         GENERAL CONFIGURATION
 ****************************************************************************
 */

/*
 * IMPORTANT: Do not edit this file in case you are using the LKM port
 *  All the options below are configurable through the
 *  Linux kernel configuration tool (make menuconfig)
 *
 */
#ifndef IP_PORT_LKM

/*
 *===========================================================================
 *                       IPNET_MEMORY_LIMIT
 *===========================================================================
 * Defines the maximum amount of memory that the stack is allowed to use.
 * The limit must be large enough to allow enough packet buffers, packet
 * headers, sockets, timers to support the workload the system has.
 * Most memory will be used to packet buffers. Each socket can queue up to
 * (send buffer size + receive buffer size) buffer octets. Each device
 * will need up to TX + RX descriptors of MTU sized packets.
 * This parameter must be set through the IPNET_MEMORY_LIMIT kernel
 * parameter on VxWorks.
 */
#ifndef IPNET_MEMORY_LIMIT
#define IPNET_MEMORY_LIMIT (1024 * 1024 * 16)
#endif

/*
 *===========================================================================
 *                         IPNET_IS_ROUTER
 *===========================================================================
 * Define to configure IPNET as a router. IPNET can be changed into a host
 * stack after boot event if this is defined. However, IPNET cannot be
 * configured as a router if this is not set.
 */
#define IPNET_IS_ROUTER

/*
 *===========================================================================
 *                         IPNET_FASTPATH
 *===========================================================================
 * Define to configure IPNET to use IPv4/IPv6 fast path routing code.
 * This fast path is slower that the Ethernet fast path, but it works for
 * all interfaces types (incoming and outgoing), it will also work together
 * with the firewall and NAT.
 */
#ifdef IPNET_IS_ROUTER
#define	IPNET_FASTPATH
#endif

/*
 *===========================================================================
 *                      IPNET_ETH_FASTPATH
 *===========================================================================
 * Define to configure IPNET to use IPv4/IPv6 Ethernet specific fast path
 * routing code. The Ethernet fast path must be enabled on a per-interface
 * basis, both the ingress and egress Ethernet interface must have the
 * IFF_LINK2 flag set before a flow can be used in Ethernet fast path
 * forwarding.
 */
#if defined(IPNET_FASTPATH) && defined(IPCOM_USE_ETHERNET)
#define IPNET_ETH_FASTPATH
#endif

/*
 *===========================================================================
 *                   IPNET_IPV4_FORWARD_CACHE_ORDER
 *===========================================================================
 * Defines the order of the IPv4 forwarding cache, number of entries are
 * (1 << order). Every entry takes ~24 bytes on a 32-bit CPU and ~32 bytes on
 * a 64-bit CPU.
 */
#define IPNET_IPV4_FORWARD_CACHE_ORDER 10

/*
 *===========================================================================
 *                   IPNET_IPV6_FORWARD_CACHE_ORDER
 *===========================================================================
 * Defines the order of the IPv6 forwarding cache, number of entries are
 * (1 << order). Every entry takes ~52 bytes on a 32-bit CPU and ~56 bytes on
 * a 64-bit CPU.
 */
#define IPNET_IPV6_FORWARD_CACHE_ORDER 10

/*
 *===========================================================================
 *                 IPNET_USE_ROUTE_TABLE_NAMES
 *===========================================================================
 * Define to get support for naming each route table. The name can then
 * be used to get the underlying virtual router index and table ID.
 *
 * This configuration allocates some extra memory.
 */
#define IPNET_USE_ROUTE_TABLE_NAMES


/*
 *===========================================================================
 *                 IPNET_USE_SCAN_GW_AT_DELETE
 *===========================================================================
 * Define if the stack should delete all route entries that uses a
 * gateway that becomes unreachable after removal of a route entry.
 *
 * This configuration transforms the route delete operation from being
 * O(log(N)) to O(N) (if defined). So it is not possible, from a practical
 * standpoint, to have this enabled on systems where the route table/FIB
 * holds large amount of entries.
 *
#define IPNET_USE_SCAN_GW_AT_DELETE
 */

/*
 *===========================================================================
 *                    IPNET_USE_ECMP_HIGHEST_RANDOM_WEIGHT
 *===========================================================================
 * IPNET has 2 different algorithms to select which route to use when there
 * are more than 1 route that is equally good to use (equal cost multipath
 * routing). Both algorithms are described in RFC 2991.
 * The IPNET_USE_ECMP_HIGHEST_RANDOM_WEIGHT controls which algorithm to use
 * Not defined: will use "Modulo-N Hash"
 * Defined: will use "Highest Random Weight"
 *
#define IPNET_USE_ECMP_HIGHEST_RANDOM_WEIGHT
 */

/*
 *===========================================================================
 *                 IPNET_USE_RFC1812_SRC_ADDR_VALIDATION
 *===========================================================================
 * Define to perform Source Address Validation as described in RFC
 * 1812, chapter 5.3.8:
 * A router SHOULD IMPLEMENT the ability to filter traffic based on a
 * comparison of the source address of a packet and the forwarding
 * table for a logical interface on which the packet was received.
 * If this feature is implemented, it MUST be disabled by default.
 *
#define IPNET_USE_RFC1812_SRC_ADDR_VALIDATION
 */

/*
 *===========================================================================
 *                         IPNET_INCLUDE_CMD
 *===========================================================================
 * Define to include IPNET shell commands (ifconfig, route, netstat,
 * ipnet_ctrl, arp, ping, ndp, ping6, tunnel, etc.)
 */
#if IPCOM_USE_SHELL != IPCOM_SHELL_NONE
#define IPNET_INCLUDE_CMD
#endif

/*
 *===========================================================================
 *                     IPNET_INCLUDE_CMD_SCALETEST
 *===========================================================================
 * Define to include IPNET:s algorithm scaling test.
 *
#define IPNET_INCLUDE_CMD_SCALETEST
 */

/*
 *===========================================================================
 *                         IPNET_COMPAT_OLDSOCK
 *===========================================================================
 * Makes IPNET able to run old socket code using the 16-bit sin_family from
 * struct sockaddr_in instead of the newer 8-bit version + length mapping
 * directly against the struct sockaddr.
 */
#define IPNET_COMPAT_OLDSOCK

/*
 *===========================================================================
 *                IPNET_USE_RFC4941/IPNET_USE_RFC3041
 *===========================================================================
 * Define to include support for RFC 4941. RFC 4941 obsoletes RFC 3041.
 * Definiting RFC 4941 will also enable support for RFC 3041 so that
 * any code that depends on the old define still works.
 * "Privacy Extensions for Stateless Address Autoconfiguration in IPv6"
 * Note this option requires one of IPMCRYPTO or IPCRYPTO products.
 */
#if defined(IPCOM_USE_MD5) && !defined(OPENSSL_FIPS)
#define IPNET_USE_RFC4941
#endif

#ifdef IPNET_USE_RFC4941
#define IPNET_USE_RFC3041
#endif

/*
 *===========================================================================
 *                   IPNET_IPV6_RFC4941_MAX_DESYNC_FACTOR
 *===========================================================================
 * Defines the maximum value of the resynchronization factor.
 * The resynchronization factor is a random duration (in seconds) in the
 * interval [0..MAX_DESYNC_FACTOR] generated on each host at boot.
 * The MAX_DESYNC_FACTOR is included timeout calculations of temporary
 * addresses to avoid that all clients updates their temporary addresses at
 * the same time.
 */
#if ((defined(IPNET_USE_RFC3041) || defined(IPNET_USE_RFC4941)) \
     && !defined(IPNET_IPV6_RFC4941_MAX_DESYNC_FACTOR))
#define IPNET_IPV6_RFC4941_MAX_DESYNC_FACTOR 600
#endif


/*
 *===========================================================================
 *                    IPNET_USE_RFC1256
 *===========================================================================
 * Define to include support for RFC 1256
 * "ICMP Router Discovery Messages"
 * This is an extension of the Internet Control Message Protocol (ICMP)
 * to enable hosts attached to multicast or broadcast networks to discover
 * the IP addresses of their neighboring routers.
 */
#define IPNET_USE_RFC1256

/*
 *===========================================================================
 *                    IPNET_RFC1256_ENABLE_ADVERTISEMENT
 *===========================================================================
 * If defined, RFC1256 advertisements will be on by default if the
 * the host is configured as a router, for all interfaces where forwarding
 * is enabled.
#define IPNET_RFC1256_ENABLE_ADVERTISEMENT
 */

/*
 *===========================================================================
 *                    IPNET_RFC1256_ENABLE_SOLICITATION
 *===========================================================================
 * If defined, RFC1256 solicitations will be enabled by default if the
 * the target is configured as a host, for all interfaces where forwarding
 * is not enabled.
#define IPNET_RFC1256_ENABLE_SOLICITATION
 */

/*
 *===========================================================================
 *                    IPNET_USE_RFC3927
 *===========================================================================
 * Define to include support for RFC 3927
 * "Dynamic Configuration of IPv4 Link-Local Addresses"
 * The link local IPv4 addresses is the 169.254/16 network.
 * The feature is currently only supported on Ethernet and IEEE 802.11
 * interfaces.
 */
#ifdef IPCOM_USE_ETHERNET
#define IPNET_USE_RFC3927
#endif

/*
 *===========================================================================
 *                    IPNET_USE_RFC4443
 *===========================================================================
 * Define to make make usage of the new ICMPv6 destintation unreachable
 * codes defined in this RFC.
 * The node will be able to process ICMPv6 messages containing RFC4443
 * codes regardless of the state of this define, but it will only use them
 * in messages generated by this node if IPNET_USE_RFC4443 is defined.
 *
 */
#define IPNET_USE_RFC4443

/*
 *===========================================================================
 *                         IPNET_USE_PCAP
 *===========================================================================
 * Define to include support for generation of PCAP compatible dumps from
 * the stack.
 */
#if !defined(IPBASIC) && !defined(IP_SIZE) && IPCOM_USE_FILE != IPCOM_FILE_NONE
#define IPNET_USE_PCAP
#endif

/*
 *===========================================================================
 *                         IPNET_USE_RFC3971
 *===========================================================================
 * Define to include support for Secure Neighbor Discovery, SEND, defined
 * in RFC 3971
#define IPNET_USE_RFC3971
 */

/*
 ****************************************************************************
 *                         PACKET POOL CONFIGURATION
 ****************************************************************************
 */
/*
 *===========================================================================
 *                         IPNET_USE_PACKET_POOL
 *===========================================================================
 * Use the IPNET internal packet pool.
 * If defined, IPNET will allocate all packets from this pool.
 * Otherwise IPNET will allocate packets from a pool provided by the
 * operating system.
 */
#define IPNET_USE_PACKET_POOL


/*
 *===========================================================================
 *                    IPNET_USE_PER_CPU_PKT_CACHE
 *===========================================================================
 * Define to include per-CPU packet pool cache for IPNET.
 */
#ifdef IPNET_USE_PACKET_POOL
#define IPNET_USE_PER_CPU_PKT_CACHE
#endif


/*
 *===========================================================================
 *                    IPNET_USE_PER_CPU_PKT_CACHE_SPINLOCK
 *===========================================================================
 * Define if the per-CPU packet cache should be protected using an ipcom
 * spinlock rather than preemption locking.
 */
#ifdef IPNET_USE_PER_CPU_PKT_CACHE
/*
 * Until the ipcom preemption locking APIs are finalized and implemented on
 * all ports, we use the spinlock on ports where the APIs are not yet
 * implemented. (We might also want to consider CPU architecture.)
 * Also, when debugging is enabled, preemption locking is not sufficient
 * since there are some cross-cpu packet cache accesses in the ipnet_cmd_ctrl
 * code.
 */
#if !defined (IP_PORT_VXWORKS) || defined (IPNET_DEBUG)
#define IPNET_USE_PER_CPU_PKT_CACHE_SPINLOCK
#endif
#endif



/*
 *===========================================================================
 *                         ipnet_conf_pkt_pool
 *===========================================================================
 * Array that describes the number of and sizes of the packets in the packet
 * pool. The largest MTU in this list should be equal or larger than
 * the MTU of any network interface used on this target.
 */
#ifdef IPNET_USE_PACKET_POOL
IP_EXTERN IP_CONST Ipnet_conf_pkt_pool ipnet_conf_pkt_pool_buf[];
IP_EXTERN IP_CONST Ipnet_conf_pkt_pool *ipnet_conf_pkt_pool;
#endif /* IPNET_USE_PACKET_POOL */


/*
 ****************************************************************************
 *                         NETIF CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_SOCKDEV
 *===========================================================================
 * Define include support for the IP_AF_SOCKDEV domain.
 * Every socket in this domain has a one-to-one mapping to a network
 * interface of type IP_IFF_SOCKDEV in the stack. Every frame sent to that
 * interface by IPNET can be read on the socket. Every frame written to
 * the socket will appear as a received IP datagram on the corresponding
 * interface in IPNET.
#define IPNET_USE_SOCKDEV
 */

/*
 *===========================================================================
 *                         IPNET_USE_VRRP
 *===========================================================================
 * Define to included support for Virtual Router Redundancy Protocol (RFC3768).
 * Must always be defined when building the LAS port.
 */
#ifdef IP_PORT_LAS
#define IPNET_USE_VRRP
#endif


/*
 *===========================================================================
 *                      IPNET_STRICT_MODE
 *===========================================================================
 * Define to put IPNET in strict mode, undefine for loose mode.
 * Strict mode requires packet to enter on the correct interface to be
 * considered local. Loose mode will accept the packet if any interface
 * has the unicast address. Most OS:es uses loose mode.
#define IPNET_STRICT_MODE
 */


/*
 *===========================================================================
 *                      IPNET_USE_IFO_x
 *===========================================================================
 * Define which queue types that should be possible to use as interface
 * output queues.
 */

/*** Actual queues (leaf nodes for containers) ***/
/* First In First Out */
#define IPNET_USE_IFO_FIFO

#ifdef IPNET_MSP_DISTRIBUTION  /* FIFO available always, the rest MSP only */

/* Drop Precedence Aware FIFO */
#define IPNET_USE_IFO_DPAF
/* Random Early Detection */
/*#define IPNET_USE_IFO_RED*/
/* Network emulator */
#define IPNET_USE_IFO_NETEMU
/* Null queue (black hole) */
#define IPNET_USE_IFO_NULL

/*** Containers for queues (which queue the packet ends up in depends on its class) ***/
/* Multi Band Container */
#define IPNET_USE_IFO_MBC
/* Hierarchical Token Bucket Container */
#define IPNET_USE_IFO_HTBC

#endif /* IPNET_MSP_DISTRIBUTION */


/*
 ****************************************************************************
 *                         SOCKET CONFIGURATION
 ****************************************************************************
 */


/*
 ****************************************************************************
 *                         MULTICAST CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                    IPNET_USE_SOURCE_SPECIFIC_MCAST
 *===========================================================================
 * Define to include support for IGMPv3 and MLDv2.
 * IGMPv2 and MLDv1 will be used it this feature is disabled.
 * The only reason to disable this is to make the stack smaller.
 */
#define IPNET_USE_SOURCE_SPECIFIC_MCAST

#ifdef IPNET_MSP_DISTRIBUTION


/*
 *===========================================================================
 *                         IPNET_USE_MCAST_ROUTING
 *===========================================================================
 * Define included support for multicast routing (IPv4 and IPv6).
 */
#define IPNET_USE_MCAST_ROUTING



/*
 ****************************************************************************
 *                       IP TUNNEL CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_TUNNEL
 *===========================================================================
 * Define includes support for tunnel network interfaces. The interaces will
 * be called gifX.
 */
#if defined(IPCOM_USE_INET) && defined(IPNET_USE_MCAST_ROUTING)
#define IPNET_USE_TUNNEL
#endif /* IPCOM_USE_INET && IPNET_USE_MCAST_ROUTING */


/*
 *===========================================================================
 *                         IPNET_USE_SIT
 *===========================================================================
 * Define includes support for SIT tunnel network interfaces. The interfaces
 * will be called sitX and is used to automatically tunnel IPv6 packets
 * over IPv4 when IPv6-compatible-IPv4 addresses are used.
 */
#if defined(IPNET_USE_TUNNEL) && defined(IPCOM_USE_INET) && defined(IPCOM_USE_INET6)
#define IPNET_USE_SIT
#endif


/*
 *===========================================================================
 *                         IPNET_USE_6TO4
 *===========================================================================
 * Define includes support for RFC3056 6to4 tunnel network interfaces. The
 * interfaces will be called 6to4X and is used to automatically tunnel IPv6
 * packets over IPv4 using 2002:IPv4::/48 addresses.
 */
#if defined(IPNET_USE_TUNNEL) && defined(IPCOM_USE_INET) && defined(IPCOM_USE_INET6)
#define IPNET_USE_6TO4
#endif


/*
 *===========================================================================
 *                         IPNET_USE_6OVER4
 *===========================================================================
 * Define includes support for RFC2529 6over4 tunnel network interfaces. The
 * interfaces will be called 6over4X. A local IPv4 must be selected as the
 * link address (via the IP_SIOCCHGTUNNEL ioctl).
 */
#if defined(IPNET_USE_TUNNEL) && defined(IPCOM_USE_INET) && defined(IPCOM_USE_INET6)
#define IPNET_USE_6OVER4
#endif


/*
 *===========================================================================
 *                         IPNET_USE_GRE
 *===========================================================================
 * Define includes support for GRE tunnel network interfaces. The interfaces
 * will be called greX.
 */
#ifdef IPNET_USE_TUNNEL
#define IPNET_USE_GRE
#endif


/*
 *===========================================================================
 *                       IPNET_USE_RFC2890
 *===========================================================================
 * Define to include support for sequence number and key option in GRE
 *  tunnels.
 */
#ifdef IPNET_USE_GRE
#define IPNET_USE_RFC2890
#endif

#endif /* IPNET_MSP_DISTRIBUTION */

/*
 ****************************************************************************
 *                       DIFFERENTIATED SERVICES
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_DIFFSERV
 *===========================================================================
 * Define to include support for differentiated services.
 */
#ifdef IPNET_MSP_DISTRIBUTION
#define IPNET_USE_DIFFSERV
#endif /* IPNET_MSP_DISTRIBUTION */

/*
 *===========================================================================
 *                    IPNET_DIFFSERV_CLASSIFIER_MODE_BA
 *===========================================================================
 * Define to run the classifier in Behavior Aggregate mode. IPNET will
 * only look at the DS field (TOS for IPv4, traffic class for IPv6)
 * when classifying traffic.
 * Undefine to run the classifier in Multi-Field mode, this is slower than
 * BA mode but it is now possible to match traffic on any field supported
 * by the IPNET classifier.
 */
#ifdef IPNET_USE_DIFFSERV
#define IPNET_DIFFSERV_CLASSIFIER_MODE_BA
#endif

/*
 ****************************************************************************
 *                         LINK CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_LOOPBACK
 *===========================================================================
 * Define for Loopback support, must be define for all ports except LKM.
 */
#define IPNET_USE_LOOPBACK


/*
 *===========================================================================
 *                         IPNET_USE_VLAN
 *===========================================================================
 * Define for IPNET 802.1Q virtual LAN support. The interfaces will be called
 * vlanX.
 */
#ifdef IPNET_MSP_DISTRIBUTION
#ifdef IPCOM_USE_ETHERNET
#define IPNET_USE_VLAN
#endif
#endif /* IPNET_MSP_DISTRIBUTION */


/*
 *===========================================================================
 *                  IPNET_USE_PER_SOCKET_VLAN_TAG
 *===========================================================================
 * Define to make it possible to set the VLAN ID and VLAN priority of
 * outgoing Ethernet frames via the IP_SO_VLAN socket option.
 */
#ifdef IPNET_USE_VLAN
#define IPNET_USE_PER_SOCKET_VLAN_TAG
#endif


/*
 *===========================================================================
 *                         IPNET_USE_WLAN
 *===========================================================================
 * Define for IPNET WLAN support.
 */
#if defined(IPWLAN) || defined(IPPRISM) || defined(IP8021X)
#define IPNET_USE_WLAN
#endif

/*
 *===========================================================================
 *                         IPNET_USE_RARP
 *===========================================================================
 * Define for IPNET RARP support.
 * Note: Use "inet rarp" in ipnet_config.c interface structure to enable.
 */
#ifdef IPCOM_USE_INET
#define IPNET_USE_RARP
#endif


/*
 ****************************************************************************
 *                         ROUTING SOCKET CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_ROUTESOCK
 *===========================================================================
 * Define for routing socket support.
 */
#define IPNET_USE_ROUTESOCK

/*
 *===========================================================================
 *                         IPNET_USE_ROUTESOCK_LINKINFO
 *===========================================================================
 * Define if you want information about added, deleted or changed ARP
 * and NDP entries sent to listening routing sockets as well.
 * #define IPNET_USE_ROUTESOCK_LINKINFO
 */


/*
 ****************************************************************************
 *                         NETLINK SOCKET CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_NETLINK
 *===========================================================================
 * Define wether or not to use the Linux compatible NETLINK interface
 *
 */
#ifdef IPNET_USE_RFC3971
#define IPNET_USE_NETLINKSOCK
#endif
#ifdef IPNET_USE_NETLINKSOCK
#define IPNET_USE_NETLINK
#endif

/*
 ****************************************************************************
 *                         NETLINK SOCKET CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                 IPNET_COMPENSATE_UNRELIABLE_NETLINK
 *===========================================================================
 * Makes IPNET compensate for the unlikely event of dropped messages, by
 * regenerating a netlink "new neighbor" event for each transmission until
 * the neighbor has been acknowledged by an ARP/ND daemon.
 *
 * Applicable only with IPNET configured to do neighbor solication via an
 * ARP/ND daemon
 * #define IPNET_COMPENSATE_UNRELIABLE_NETLINK
 */

/*
 ****************************************************************************
 *                     INTERFACE MANAGEMENT CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                 IPNET_USE_ROUTE_COOKIES
 *===========================================================================
 * Define to get support for tagging each route table and route entry with
 * a user supplied finger print.
 *
 * This configuration allocates some extra memory.
 #define IPNET_USE_ROUTE_COOKIES
*/

/*
 *===========================================================================
 *                 IPNET_USE_FAST_IFNAME_LOOKUP
 *===========================================================================
 * Configure for fast (constant time) interface name lookup in IPNET.
 * Should be enabled on systems with a huge amount of interfaces (>10000)
 *
 * This configuration allocates some extra memory.
#define IPNET_USE_FAST_IFNAME_LOOKUP
 */

/*
 *===========================================================================
 *                 IPNET_SKIP_IFNAME_CHECK_ON_ATTACH
 *===========================================================================
 * Configure IPNET to skip checking for duplicate names when attaching new
 * interfaces.
 *
 * Only enable this if name checking is done externally by the OS
 * (this is the case for the IPCOM LKM port).
 *===========================================================================
#define IPNET_SKIP_IFNAME_CHECK_ON_ATTACH
*/


/*
 ****************************************************************************
 *                         NAT CONFIGURATION
 ****************************************************************************
 */

/*
 *===========================================================================
 *                         IPNET_USE_NAT
 *===========================================================================
 * Define for NAT support
 */
#if defined(IPCOM_USE_INET) && defined(IPNET_MSP_DISTRIBUTION) && !defined(IPBASIC)
#define IPNET_USE_NAT
#endif


/*
 *===========================================================================
 *                         IPNET_USE_NAT_PT
 *===========================================================================
 * Define for NAT-PT support
 */
#if defined(IPNET_USE_NAT) && defined(IPCOM_USE_INET) && defined(IPCOM_USE_INET6)
#define IPNET_USE_NAT_PT
#endif

/* NAT-PT requires NAT */
#ifdef IPNET_USE_NAT_PT
#ifndef IPNET_USE_NAT
#error NAT-PT requires NAT
#endif
#endif


/*
 *===========================================================================
 *                         IPNET_USE_NAT_FTP_ALG
 *===========================================================================
 * Define to enable the FTP ALG
 */
#define IPNET_USE_NAT_FTP_ALG

/*
 *===========================================================================
 *                         IPNET_USE_NAT_DNS_ALG
 *===========================================================================
 * Define to enable the DNS ALG
 */
#ifdef IPNET_USE_NAT_PT
#define IPNET_USE_NAT_DNS_ALG
#endif

/*
 *===========================================================================
 *                         IPNET_USE_NAT_IPSEC_ALG
 *===========================================================================
 * Define to enable the IPSEC ALG
 */
#define IPNET_USE_NAT_IPSEC_ALG

/*
 *===========================================================================
 *                         IPNET_USE_NAT_PPTP_ALG
 *===========================================================================
 * Define to enable the PPTP ALG
 */
#define IPNET_USE_NAT_PPTP_ALG

/*
 *===========================================================================
 *                         IPNET_USE_NAT_H323_ALG
 *===========================================================================
 * Define to enable the H323 ALG
 */
#define IPNET_USE_NAT_H323_ALG

/*
 *===========================================================================
 *                         IPNET_USE_NAT_SIP_ALG
 *===========================================================================
 * Define to enable the SIP ALG
 */
#define IPNET_USE_NAT_SIP_ALG

/*
 *===========================================================================
 *                         IPNET_USE_NAT_TRIGGER_ALG
 *===========================================================================
 * Define to enable the port trigger ALG
 */
#define IPNET_USE_NAT_TRIGGER_ALG

/*
 *===========================================================================
 *                         IPNET_USE_LINK_STUB
 *===========================================================================
 * Define to enable the link stub implementation for bypassing
 * ethernet processing( for use with ipcom_drv_mux.c only)
 */
#define IPNET_USE_LINK_STUB


#endif /* IP_PORT_LKM */


/*
 *===========================================================================
 *                         ipnet_conf_memory_limit
 *===========================================================================
 * Defines the maximum amount of memory that the stack is allowed to use.
 * The limit must be large enough to allow enough packet buffers, packet
 * headers, sockets, timers to support the workload the system has.
 * Most memory will be used to packet buffers. Each socket can queue up to
 * (send buffer size + receive buffer size) buffer octets. Each device
 * will need up to TX + RX descriptors of MTU sized packets.
 */
IP_EXTERN IP_CONST unsigned ipnet_conf_memory_limit;

/*
 *===========================================================================
 *                         ipnet_conf_max_sockets
 *===========================================================================
 * Maximum number of sockets that can be used at any time (the actual number
 * of available sockets will be 3 less since 0,1 and 2 is reserved).
 */
IP_EXTERN IP_CONST int ipnet_conf_max_sockets;


/*
 *===========================================================================
 *                         ipnet_conf_link_layer
 *===========================================================================
 * Array of link layer types and a initialize functions that knows how
 * to initialize the Ipnet_netif structure.
 */
IP_EXTERN IP_CONST Ipnet_conf_link_layer_init ipnet_conf_link_layer[];

/*
 *===========================================================================
 *                         ipnet_conf_inq_max
 *===========================================================================
 * Maximum number of buffers in input queue processed by the input daemon.
 */
IP_EXTERN IP_CONST int ipnet_conf_inq_max;

/*
 *===========================================================================
 *                   ipnet_conf_reassembly_timeout
 *===========================================================================
 * Number of seconds IPNET will keep incomplete datagram fragments in the
 * reassembly list before discarding them. RFC2460 states default 60 seconds.
 *
 */
IP_EXTERN IP_CONST int ipnet_conf_reassembly_timeout;

/*
 *===========================================================================
 *                         ipnet_conf_cache_bufsiz
 *===========================================================================
 * Trailing Ipcom_pkt cache buffer to protect dynamic buffer end marks.
 */
IP_EXTERN Ip_u16 ipnet_conf_cache_bufsiz;

/*
 *===========================================================================
 *                         ipnet_conf_interfaces
 *===========================================================================
 * Interface configuration that is set during system boot.
 */
IP_EXTERN IP_CONST char *ipnet_conf_interfaces[];

/*
 *===========================================================================
 *                         ipnet_conf_routes
 *===========================================================================
 * Route table configuration that is set during system boot.
 */
IP_EXTERN IP_CONST char *ipnet_conf_boot_cmd[];

/*
 *===========================================================================
 *                         ipnet_conf_ip4_min_mtu
 *===========================================================================
 * The smallest MTU that IPNET expects for IPv4. Should be 576 in most cases.
 */
IP_EXTERN IP_CONST Ip_u16 ipnet_conf_ip4_min_mtu;

/*
 *===========================================================================
 *                         ipnet_conf_ip6_min_mtu
 *===========================================================================
 * The smallest MTU that IPNET expects for IPv6. Should be 1280 in most cases.
 */
IP_EXTERN IP_CONST Ip_u16 ipnet_conf_ip6_min_mtu;

/*
 *===========================================================================
 *                     ipnet_conf_max_reassembly_list_len
 *===========================================================================
 * Maximum number of partially reassembled IP-datagrams the stack will
 * keep around.
 */
IP_EXTERN IP_CONST unsigned ipnet_conf_max_reassembly_list_len;

/*
 *===========================================================================
 *                    ipnet_conf_max_dgram_frag_list_len
 *===========================================================================
 * Maximum number of fragments a single IP-datagram can consist of.
 */
IP_EXTERN IP_CONST unsigned ipnet_conf_max_dgram_frag_list_len;

/*
 ****************************************************************************
 *                     MISC AUTO CONFIG/VERIFICATION
 ****************************************************************************
 */

#if !defined(IPCOM_USE_INET) && !defined(IPCOM_USE_INET6)
#error Must_define__IPNET_INET4__andor__IPNET_INET6
#endif

/* IPSSL use old socket structures. */
#if defined(IPSSL) && !defined(IPNET_COMPAT_OLDSOCK)
#define IPNET_COMPAT_OLDSOCK
#endif

#ifdef __cplusplus
}
#endif

#endif


/*
 ****************************************************************************
 *                      END OF FILE
 ****************************************************************************
 */

