#ifndef __CEPH_FEATURES
#define __CEPH_FEATURES

/*
 * feature bits
 */
#define CEPH_FEATURE_UID            (1<<0)
#define CEPH_FEATURE_NOSRCADDR      (1<<1)
#define CEPH_FEATURE_MONCLOCKCHECK  (1<<2)
#define CEPH_FEATURE_FLOCK          (1<<3)
#define CEPH_FEATURE_SUBSCRIBE2     (1<<4)
#define CEPH_FEATURE_MONNAMES       (1<<5)
#define CEPH_FEATURE_RECONNECT_SEQ  (1<<6)
#define CEPH_FEATURE_DIRLAYOUTHASH  (1<<7)
#define CEPH_FEATURE_OBJECTLOCATOR  (1<<8)
#define CEPH_FEATURE_PGID64         (1<<9)
#define CEPH_FEATURE_INCSUBOSDMAP   (1<<10)
#define CEPH_FEATURE_PGPOOL3        (1<<11)
#define CEPH_FEATURE_OSDREPLYMUX    (1<<12)
#define CEPH_FEATURE_OSDENC         (1<<13)
#define CEPH_FEATURE_OMAP           (1<<14)

/*
 * Features supported.  Should be everything above.
 */
#define CEPH_FEATURES_SUPPORTED_DEFAULT  \
	(CEPH_FEATURE_UID |		 \
	 CEPH_FEATURE_NOSRCADDR |	 \
	 CEPH_FEATURE_MONCLOCKCHECK |	 \
	 CEPH_FEATURE_FLOCK |		 \
	 CEPH_FEATURE_SUBSCRIBE2 |	 \
	 CEPH_FEATURE_MONNAMES |	 \
	 CEPH_FEATURE_RECONNECT_SEQ |	 \
	 CEPH_FEATURE_DIRLAYOUTHASH |	 \
	 CEPH_FEATURE_OBJECTLOCATOR |	 \
	 CEPH_FEATURE_PGID64 |		 \
	 CEPH_FEATURE_INCSUBOSDMAP |	 \
	 CEPH_FEATURE_PGPOOL3 |		 \
	 CEPH_FEATURE_OSDREPLYMUX |	 \
	 CEPH_FEATURE_OSDENC |		 \
	 CEPH_FEATURE_OMAP)

#endif