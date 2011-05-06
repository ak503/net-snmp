/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ifXTable.h"


#include "ifXTable_data_access.h"

/** @defgroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifXTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * IF-MIB::ifXTable is subid 1 of ifMIBObjects.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.31.1.1, length: 9
 */

/**
 * initialization for ifXTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ifXTable_reg
 *        Pointer to ifXTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ifXTable_init_data(ifXTable_registration * ifXTable_reg)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_init_data", "called\n"));

    /*
     * TODO:303:o: Initialize ifXTable data.
     */

    return MFD_SUCCESS;
}                               /* ifXTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ifXTable_container_init(netsnmp_container ** container_ptr_ptr,
                        netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_container_init", "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to ifXTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR, "bad cache param to ifXTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up ifXTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = IFXTABLE_CACHE_TIMEOUT;    /* seconds */
}                               /* ifXTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before ifXTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
ifXTable_container_shutdown(netsnmp_container * container_ptr)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_container_shutdown",
                "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR, "bad params to ifXTable_container_shutdown\n");
        return;
    }

}                               /* ifXTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement ifXTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ifXTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ifXTable_container_load(netsnmp_container * container)
{
    ifXTable_rowreq_ctx *rowreq_ctx;
    size_t          count = 0;

    /*
     * temporary storage for index values
     */
    /*
     * ifIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
     */
    long            ifIndex;


    DEBUGMSGTL(("verbose:ifXTable:ifXTable_container_load", "called\n"));

    /*
     * TODO:351:M: |-> Load/update data in the ifXTable container.
     * loop over your ifXTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while (1) {
        /*
         * check for end of data; bail out if there is no more data
         */
        if (1)
            break;

        /*
         * TODO:352:M: |   |-> set indexes in new ifXTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        rowreq_ctx = ifXTable_allocate_rowreq_ctx(NULL);
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if (MFD_SUCCESS != ifXTable_indexes_set(rowreq_ctx, ifIndex)) {
            snmp_log(LOG_ERR, "error setting index while loading "
                     "ifXTable data.\n");
            ifXTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate ifXTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
         * non-TRANSIENT data: no need to copy. set pointer to data 
         */

        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
        ++count;
    }

    DEBUGMSGT(("verbose:ifXTable:ifXTable_container_load",
               "inserted %d records\n", count));

    return MFD_SUCCESS;
}                               /* ifXTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
ifXTable_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_container_free", "called\n"));

    /*
     * TODO:380:M: Free ifXTable container data.
     */
}                               /* ifXTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ifXTable_row_prep(ifXTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_row_prep", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* ifXTable_row_prep */

/*
 * TODO:420:r: Implement ifXTable index validation.
 */
/*---------------------------------------------------------------------
 * IF-MIB::ifEntry.ifIndex
 * ifIndex is subid 1 of ifEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.2.1.2.2.1.1
 * Description:
A unique value, greater than zero, for each interface.  It
            is recommended that values are assigned contiguously
            starting from 1.  The value for each interface sub-layer
            must remain constant at least from one re-initialization of
            the entity's network management system to the next re-
            initialization.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   0
 *   hint: d
 *
 * Ranges:  1 - 2147483647;
 *
 * Its syntax is InterfaceIndex (based on perltype INTEGER32)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * check validity of ifIndex external index portion
 *
 * NOTE: this is not the place to do any checks for the sanity
 *       of multiple indexes. Those types of checks should be done in the
 *       ifXTable_validate_index() function.
 *
 * @retval MFD_SUCCESS   : the incoming value is legal
 * @retval MFD_ERROR     : the incoming value is NOT legal
 */
int
ifXTable_ifIndex_check_index(ifXTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ifXTable:ifXTable_ifIndex_check_index",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:424:M: |-> Check ifXTable external index ifIndex.
     * check that index value in the table context (rowreq_ctx)
     * for the external index ifIndex is legal.
     */

    return MFD_SUCCESS;         /*  external index ifIndex ok */
}                               /* ifXTable_ifIndex_check_index */

/**
 * verify specified index is valid.
 *
 * This check is independent of whether or not the values specified for
 * the columns of the new row are valid. Column values and row consistency
 * will be checked later. At this point, only the index values should be
 * checked.
 *
 * All of the individual index validation functions have been called, so this
 * is the place to make sure they are valid as a whole when combined. If
 * you only have one index, then you probably don't need to do anything else
 * here.
 * 
 * @note Keep in mind that if the indexes refer to a row in this or
 *       some other table, you can't check for that row here to make
 *       decisions, since that row might not be created yet, but may
 *       be created during the processing this request. If you have
 *       such checks, they should be done in the check_dependencies
 *       function, because any new/deleted/changed rows should be
 *       available then.
 *
 *
 * @param ifXTable_reg
 *        Pointer to the user registration data
 * @param ifXTable_rowreq_ctx
 *        Pointer to the users context.
 * @retval MFD_SUCCESS            : success
 * @retval MFD_CANNOT_CREATE_NOW  : index not valid right now
 * @retval MFD_CANNOT_CREATE_EVER : index never valid
 */
int
ifXTable_validate_index(ifXTable_registration * ifXTable_reg,
                        ifXTable_rowreq_ctx * rowreq_ctx)
{
    int             rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:ifXTable:ifXTable_validate_index", "called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:430:M: |-> Validate potential ifXTable index.
     */
    if (1) {
        snmp_log(LOG_WARNING, "invalid index for a new row in the "
                 "ifXTable table.\n");
        /*
         * determine failure type.
         *
         * If the index could not ever be created, return MFD_NOT_EVER
         * If the index can not be created under the present circumstances
         * (even though it could be created under other circumstances),
         * return MFD_NOT_NOW.
         */
        if (0) {
            return MFD_CANNOT_CREATE_EVER;
        } else {
            return MFD_CANNOT_CREATE_NOW;
        }
    }

    return rc;
}                               /* ifXTable_validate_index */

/** @} */