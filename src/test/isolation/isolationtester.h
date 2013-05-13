/*-------------------------------------------------------------------------
 *
 * isolationtester.h
 *	  include file for isolation tests
 *
 * Portions Copyright (c) 1996-2014, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * IDENTIFICATION
 *		src/test/isolation/isolationtester.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef ISOLATIONTESTER_H
#define ISOLATIONTESTER_H

typedef struct Session Session;
typedef struct Step Step;

struct Session
{
	char	   *name;
	char	   *connection;
	int         connidx;
	char       *backend_pid;
	char	   *setupsql;
	char	   *teardownsql;
	Step	  **steps;
	int			nsteps;
};

struct Step
{
	int			session;
	char	   *name;
	char	   *sql;
	char	   *errormsg;
};

typedef struct
{
	int			nsteps;
	char	  **stepnames;
}	Permutation;

typedef struct
{
	char       *name;
	const char *conninfo;
	char      **pids;
	int         npids;
	char       *pidlist;
} Connection;

typedef struct
{
	Connection **conninfos;
	int         nconninfos;
	char	  **setupsqls;
	int			nsetupsqls;
	char	   *teardownsql;
	Session   **sessions;
	int			nsessions;
	Permutation **permutations;
	int			npermutations;
}	TestSpec;

extern TestSpec parseresult;

extern int	spec_yyparse(void);

extern int	spec_yylex(void);
extern void spec_yyerror(const char *str);

#endif   /* ISOLATIONTESTER_H */
