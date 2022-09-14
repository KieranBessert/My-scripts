update ae_c_api_e_udf
set custom001 = 'Y'
where tranx_no in (select tranx_no
from ae_c_api_e
                where invoice_no IN ('I#######'))
