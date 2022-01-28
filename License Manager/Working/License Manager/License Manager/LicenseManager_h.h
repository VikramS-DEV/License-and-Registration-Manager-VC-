

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jan 27 22:16:42 2022
 */
/* Compiler settings for LicenseManager.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __LicenseManager_h_h__
#define __LicenseManager_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILicenseManager_FWD_DEFINED__
#define __ILicenseManager_FWD_DEFINED__
typedef interface ILicenseManager ILicenseManager;
#endif 	/* __ILicenseManager_FWD_DEFINED__ */


#ifndef __LicenseManager_FWD_DEFINED__
#define __LicenseManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class LicenseManager LicenseManager;
#else
typedef struct LicenseManager LicenseManager;
#endif /* __cplusplus */

#endif 	/* __LicenseManager_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LicenseManager_LIBRARY_DEFINED__
#define __LicenseManager_LIBRARY_DEFINED__

/* library LicenseManager */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_LicenseManager;

#ifndef __ILicenseManager_DISPINTERFACE_DEFINED__
#define __ILicenseManager_DISPINTERFACE_DEFINED__

/* dispinterface ILicenseManager */
/* [uuid] */ 


EXTERN_C const IID DIID_ILicenseManager;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("43A21C41-3300-4795-B00C-9EBCC206996A")
    ILicenseManager : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILicenseManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILicenseManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILicenseManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILicenseManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILicenseManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILicenseManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILicenseManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILicenseManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ILicenseManagerVtbl;

    interface ILicenseManager
    {
        CONST_VTBL struct ILicenseManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILicenseManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILicenseManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILicenseManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILicenseManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILicenseManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILicenseManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILicenseManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILicenseManager_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LicenseManager;

#ifdef __cplusplus

class DECLSPEC_UUID("FEC12A09-80FB-4DE8-8826-59A1D7A26DDC")
LicenseManager;
#endif
#endif /* __LicenseManager_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


