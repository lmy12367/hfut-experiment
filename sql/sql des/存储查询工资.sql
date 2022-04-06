create procedure c_wage_info
	@stanum char(8) output,
	@bw numeric(5,2) out,
	@allo numeric(5,2) out,
	@whop numeric(5,2) out,
	@pm numeric(5,2) out
	as
	select @bw, @allo, @whop, @pm
	from wage
	where @stanum=stanum