use [Music]
go
insert into Artist (artist_id, artist_name) 
select distinct artist_id, artist_name from [Music Data File]

go
insert into [dbo].[Album]
           ([artist_id],[album_id] ,[album_name] ,[genre] ,[album_length]
           ,[recording_label],[release_date],[recording_no])

select distinct [artist_id],[albumid] ,[album_name] ,[genre] ,[albums_length]
           ,[recordinglabel],[releasedate],[recording_no] from [Music Data File]
   
go
go

insert into [dbo].[recording_company]
           ([recording_no]
           ,[recording_company])
select distinct [recording_no]
           ,[recording_company] from [Music Data File]
go

go

insert into [dbo].[songs]
           ([song_id]
           ,[song_title]
           ,[song_length]
           ,[album_id])
select distinct [songid],[song_title],[songs_length],[albumid] from [Music Data File]
go