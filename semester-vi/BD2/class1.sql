--CREATE or REPLACE FUNCTION increment(i INTEGER) RETURNS INTEGER AS $$
--	BEGIN
--		RETURN i + 1;
--	END
--$$ language plpgsql;

CREATE or REPLACE FUNCTION print(arg varchar) RETURNS VARCHAR AS $$
	BEGIN
		RETURN arg;
	end
$$ language plpgsql;

