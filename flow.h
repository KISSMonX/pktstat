/* David Leonard, 2002. Public domain. */
/* $Id$ */

struct flow {
	char		tag[80];
	char		desc[80];
	unsigned int	taghash;
	unsigned long	octets;
	unsigned long	total_octets;
	double		keepalive;
	int		dontdel;
	u_int32_t	seq[2];		/* seq no for TCP */
	void		*udata;
	void		(*freeudata)(void *);
	struct timeval	lastseen;
};

extern int nflows;
extern struct flow *flows;

struct flow *findflow(const char *tag);
void	     flow_zero(void);
void	     flow_del(struct flow *);

int	     octetcmp(const void *, const void *);
int	     tagcmp(const void *, const void *);
int	     lastcmp(const void *, const void *);
