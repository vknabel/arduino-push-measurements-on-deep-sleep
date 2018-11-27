require 'sinatra'
require 'sqlite3'

def prepareDb()
  db = SQLite3::Database.new 'accessories.db'
  db.execute <<-SQL
    CREATE TABLE IF NOT EXISTS measurement(
      id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
      accessory VARCHAR(50)  NOT NULL,
      loggedAt INT  NOT NULL,
      payload TEXT  NOT NULL
    );
  SQL
  return db
end

get '/accessory/:name' do |name|
  db = prepareDb
  # read latest
  query = <<-SQL
    SELECT payload FROM measurement
    WHERE accessory = ?
    ORDER BY id DESC
    LIMIT 1;
  SQL
  # AND loggedAt BETWEEN datetime('now', '-20 minutes') AND datetime('now')
  measurement = db.execute query, [name]
  measurement[0]
end

post '/accessory/:name' do |name|
  db = prepareDb
  request.body.rewind # in case someone already read it
  query = <<-SQL
    INSERT INTO measurement(loggedAt, accessory, payload)
    VALUES (datetime('now'), ?, ?);
  SQL
  db.execute query, [name, request.body.read]
end
