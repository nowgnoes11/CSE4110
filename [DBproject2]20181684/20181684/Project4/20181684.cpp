#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost";
const char* user = "root";
const char* pw = "sps598542*";
const char* db = "DBA";

int main(void) {

	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	int type, k, state = 0;
	char max_id[1000]; int max_price = 0;
	const char* query;

	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	} // ¿¬°á
	else {
		if (mysql_select_db(&conn, db))	{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}
		
		while (1) {
			printf("------- SELECT QUERY TYPES -------\n\n");
			printf("\t1. TYPE 1\n");
			printf("\t2. TYPE 2\n");
			printf("\t3. TYPE 3\n");
			printf("\t4. TYPE 4\n");
			printf("\t5. TYPE 5\n");
			printf("\t6. TYPE 6\n");
			printf("\t7. TYPE 7\n");
			printf("\t0. QUIT\n");
			scanf("%d", &type);

			if (type == 1) {
				while (1) {
					printf("------- Subtypes in TYPE 1 -------\n\n");
					printf("\t1. TYPE 1\n");
					printf("\t2. TYPE 1-1\n");
					printf("\t0. QUIT\n");
					scanf("%d", &type);

					if (type == 1) {
						char X[4];
						printf("Enter X : ");
						scanf("%s", &X);
						
						query = "select * from online_sales";
						state = mysql_query(connection, query);
						if (!state) {
							sql_result = mysql_store_result(connection);
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
							{
								if(strcmp(sql_row[2], X) == 0)
								printf("%s %s %s %s\n", sql_row[3], sql_row[4], sql_row[5], sql_row[7]);
							}
						}

					}
					else if (type == 2) {

					}
					else if (type == 0) {
						break;
					}
				}
			}
			else if (type == 2) {
				while (1) {
					printf("------- Subtypes in TYPE 2 -------\n\n");
					printf("\t1. TYPE 2\n");
					printf("\t2. TYPE 2-1\n");
					printf("\t0. QUIT\n");
					scanf("%d", &type);

					if (type == 1) {
						query = "select * from online_sales";
						state = mysql_query(connection, query);
						if (!state) {
							sql_result = mysql_store_result(connection);
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
								if (!strcmp(max_id, sql_row[3])) {
									max_price += atoi(sql_row[4]) * atoi(sql_row[9]);
								}
								else {
									if ((atoi(sql_row[4]) * atoi(sql_row[9])) > max_price) {
										strcpy(max_id, sql_row[3]);
										max_price = (atoi(sql_row[4]) * atoi(sql_row[9]));
									}
								}
							}
						}

						printf("%s %d\n", max_id, max_price);
					}
					else if (type == 2) {
						int max_buy = 0;
						query = "select * from online_sales";
						state = mysql_query(connection, query);
						if (!state) {
							sql_result = mysql_store_result(connection);
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
								if (!strcmp(max_id, sql_row[3])) {
									max_price += atoi(sql_row[4]) * atoi(sql_row[9]);
								}
								else {
									if ((atoi(sql_row[4]) * atoi(sql_row[9])) > max_price) {
										strcpy(max_id, sql_row[3]);
										max_price = (atoi(sql_row[4]) * atoi(sql_row[9]));
									}
								}
							}
						}

						printf("%s %d\n", max_id, max_price);
					}
					else if (type == 0) {
						break;
					}
				}
			}
			else if (type == 3) {
				while (1) {
					printf("------- Subtypes in TYPE 3 -------\n\n");
					printf("\t1. TYPE 3\n");
					printf("\t2. TYPE 3-1\n");
					printf("\t2. TYPE 3-2\n");
					printf("\t0. QUIT\n");
					scanf("%d", &type);

					if (type == 1) {
						query = "select distinct * from online_sales";
						state = mysql_query(connection, query);
						if (!state) {
							sql_result = mysql_store_result(connection);
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
								if (!strncmp(sql_row[10], "2021", 4))
									printf("%s %s\n", sql_row[1], sql_row[11]);
							}
						}
					}
					else if (type == 2) {
						printf("Enter k : ");
						scanf("%d", &k);

						query = "select * from online_sales";
						state = mysql_query(connection, query);
						if (!state) {
							sql_result = mysql_store_result(connection);
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
								
							}
						}

					}
					else if (type == 3) {
					
					}
					else if (type == 0)
						break;
				}
			}
			else if (type == 4) {
				while (1) {
					printf("------- Subtypes in TYPE 4 -------\n\n");
					printf("\t1. TYPE 4\n");
					printf("\t2. TYPE 4-1\n");
					printf("\t2. TYPE 4-2\n");
					printf("\t0. QUIT\n");
					scanf("%d", &type);

					if (type == 1) {
					}
					else if (type == 2) {

					}
					else if (type == 3) {

					}
					else if (type == 0)
						break;
				}
			}
			else if (type == 5) {

			}
			else if (type == 6) {
				query = "select * from online_sales";
				state = mysql_query(connection, query);
				if (!state) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
						if (atoi(sql_row[12]) - atoi(sql_row[10]) < 0)
							printf("%s %s %s\n", sql_row[0], sql_row[12], sql_row[10]);
						
					}
				}
			}
		
			else if (type == 7) {

			}
			else if (type == 0) {
				break;
			}
			else
				printf("Wrong Number (0 - 7)!\n");
		}
		//mysql_free_result(sql_result);
		mysql_close(connection);

		return 0;

	}

	
}
/*if (type == 0) {
				mysql_free_result(sql_result);
				mysql_close(connection);

				return 0;
			}*/




/*

	printf("------- SELECT QUERY TYPES -------\n\n");
	printf("\t1. TYPE 1\n");
	printf("\t2. TYPE 2\n");
	printf("\t3. TYPE 3\n");
	printf("\t4. TYPE 4\n");
	printf("\t5. TYPE 5\n");
	printf("\t6. TYPE 6\n");
	printf("\t7. TYPE 7\n");
	printf("\t0. QUIT\n");
	//printf("----------------------------------\n");
	printf("\n\n");
	printf("---- TYPE 5 ----\n\n");
	printf("** Find the top k brands by unit sales by the year**\n");
	printf(" Which K? : 3\n");

	return 0;

}
*/

/*const char* query = "select * from customer";
int state = 0;
state = mysql_query(connection, query);

if (state == 0) {
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		printf("%s %s %s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3], sql_row[4],
			sql_row[5]);
	}
}
*/