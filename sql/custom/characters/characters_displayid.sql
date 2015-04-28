CREATE TABLE `character_displayid` (
	`guid` INT UNSIGNED NOT NULL,
	`displayid` INT UNSIGNED NULL,
	PRIMARY KEY (`guid`)
)
COMMENT='Character display ID (morph)'
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;
