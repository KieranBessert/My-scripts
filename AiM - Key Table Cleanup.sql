SELECT DISTINCT table_name from information_schema.columns
WHERE COLUMN_NAME = 'copy_id';
######################################################################
UPDATE ae_kac_copy_status_hist
SET copy_status = 'INACTIVE', edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_copy_status_hist
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_key_copy
SET copy_status = 'INACTIVE', description = 'OM CHANGE - RETIRED 8/18/2022', edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_key_copy
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_key_copy_notes
SET edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_key_copy_notes
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_key_copy_udf
SET edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_key_copy_udf
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_release_d
SET edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_release_d
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_ring_keys
SET edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_ring_keys
WHERE key_id = '304A';
######################################################################
UPDATE ae_kac_ticket_d
SET edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_ticket_d
WHERE key_id = '304A';
######################################################################











SELECT DISTINCT table_name from information_schema.columns
WHERE COLUMN_NAME = 'key_id';
######################################################################
UPDATE ae_kac_key
SET Description = 'CLEARED', status_code = 'INACTIVE', edit_date = NOW(), edit_clerk = 'AiM Load'
WHERE key_id = '304A';

SELECT * FROM ae_kac_key
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_authorizer
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_core
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_core_history
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_notes
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_status_hist
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_key_storage;
######################################################################
SELECT * FROM ae_kac_key_udf
WHERE key_id = '304A';
######################################################################
SELECT * FROM ae_kac_return_d
WHERE key_id = '304A';
